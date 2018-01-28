// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var React       = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Company");

function make(company, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: "company"
                }, React.createElement("img", {
                      className: "logo",
                      alt: "",
                      src: company.logo
                    }), React.createElement("div", {
                      className: "description"
                    }, React.createElement("h2", {
                          className: "name"
                        }, company.name), React.createElement("p", {
                          className: "excerpt"
                        }, company.description)));
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */