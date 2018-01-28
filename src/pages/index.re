[%bs.raw {|require("./index.css")|}];

let component = ReasonReact.statelessComponent("Index");

let make = (~data, _children) => {
  ...component,
  render: _self =>
    <CompaniesPage
      title="Companies"
      companies=(data##companies |> Graphql.getNodes)
    />
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~data=jsProps##data, [||])
  );

[%%raw
  {|
    export const query = graphql`
    query CompaniesQuery {
      companies: allSourcesJson {
        edges {
          node {
            id
            name
            description
            logo
            url
          }
        }
      }
    }
  `
  |}
];