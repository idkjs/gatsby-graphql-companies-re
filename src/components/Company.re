let component = ReasonReact.statelessComponent("Company");

let make = (~company, _children) => {
  ...component,
  render: _self =>
    <div className="company">
      <img src=company##logo className="logo" alt="" />
      <div className="description">
        <h2 className="name"> company##name </h2>
        <p className="excerpt"> company##description </p>
      </div>
    </div>
};