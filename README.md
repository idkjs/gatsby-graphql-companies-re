# Gatsby & Reason Tester

## gatsby-node.js

* create `gatsby-node.js` in root/

## onCreateNode()

```js
exports.onCreateNode = ({ node }) => {
  console.log(node.internal.type);
};
```
