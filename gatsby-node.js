exports.onCreateNode = async ({
  node,
  loadNodeContent,
  boundActionCreators: { createNode, createParentChildLink }
}) => {
  function transformObject(obj, type) {
    const objStr = JSON.stringify(obj);
    const contentDigest = crypto
      .createHash(`md5`)
      .update(objStr)
      .digest(`hex`);
    const jsonNode = {
      ...obj,
      children: [],
      parent: node.id,
      internal: {
        contentDigest,
        type
      }
    };

    createNode(jsonNode);
    createParentChildLink({ parent: node, child: jsonNode });
  }

  if (node.internal.mediaType === "application/json") {
    const content = await loadNodeContent(node);
    const parsed = JSON.parse(content);

    if (node.sourceInstanceName === "packages") {
      const package = parsed;
      package.slug = path.join("/package", decodeURIComponent(package.id));

      await new Promise((resolve, reject) =>
        remark()
          .use(codeBlocks)
          .use(headingAnchors)
          .use(html)
          .process(package.readme, function(err, file) {
            if (err) {
              reject(err);
            } else {
              package.readme = file.contents;
              transformObject(package, "Packages");
              resolve();
            }
          })
      );
    } else {
      throw "unknown source " + node.sourceInstanceName;
    }
  }
};
