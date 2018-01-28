let ste = ReasonReact.stringToElement;

let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
)##value;
module Input = {
  let component = ReasonReact.reducerComponent("Input");
  let make = (~onSubmit, _) => {
    ...component,
    initialState: () => "",
    reducer: (newText, _text) => ReasonReact.Update(newText),
    render: self =>
      <input
        _type="text"
        placeholder="Write something to do"
        onChange=(_evt => self.send(valueFromEvent(_evt)))
        onKeyDown=(
          _evt =>
            if (ReactEventRe.Keyboard.key(_evt) == "Enter") {
              onSubmit(self.state);
              self.send("");
            }
        )
        value=self.state
      />
  };
};

let component = ReasonReact.statelessComponent("CompaniesPage");

let make = (~title, ~companies, _children) => {
  ...component,
  render: _self =>
    <div className="container">
      <Helmet title=(Config.titleTemplate(title)) />
      <h1>
        (title ++ " (" ++ string_of_int(Array.length(companies)) ++ ")" |> ste)
      </h1>
      <div className="title">
      (ste("What to do"))
      <Input onSubmit=(text => self.send(AddItem(text))) />
</div>
      (
        ReasonReact.arrayToElement(
          Array.map(company => <Company company />, companies)
        )
      )
    </div>
};