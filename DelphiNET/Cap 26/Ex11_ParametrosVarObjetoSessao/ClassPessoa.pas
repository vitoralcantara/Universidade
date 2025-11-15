unit ClassPessoa;

interface

type
  TPessoa = class
  private
    { Private Declarations }
  public
    Nome, SobreNome : string;
    constructor Create(aNome, aSobreNome : string);
  end;

implementation

constructor TPessoa.Create(aNome, aSobreNome : string);
begin
  inherited Create;
  // TODO: Add any constructor code here
  Nome := aNome;
  SobreNome := aSobreNome;
end;

end.
