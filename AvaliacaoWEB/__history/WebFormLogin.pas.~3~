
unit WebFormLogin;

interface

uses
  System.Collections, System.ComponentModel,
  System.Data, System.Drawing, System.Web, System.Web.SessionState,
  System.Web.UI, System.Web.UI.WebControls, System.Web.UI.HtmlControls,
  System.Web.Security, System.IO;

type
  TWebForm2 = class(System.Web.UI.Page)
  {$REGION 'Designer Managed Code'}
  strict private
    procedure InitializeComponent;
    procedure Button1_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict private
    procedure Page_Load(sender: System.Object; e: System.EventArgs);
  strict protected
    TextBox1: System.Web.UI.WebControls.TextBox;
    TextBox2: System.Web.UI.WebControls.TextBox;
    Button1: System.Web.UI.WebControls.Button;
    LabelMsg: System.Web.UI.WebControls.Label;
    procedure OnInit(e: EventArgs); override;
  private
    { Private Declarations }
  public
    { Public Declarations }
    function VerificaSenha(aUsuario, aSenha: String) : boolean;
  end;

implementation

{$REGION 'Designer Managed Code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure TWebForm2.InitializeComponent;
begin
  Include(Self.Button1.Click, Self.Button1_Click);
  Include(Self.Load, Self.Page_Load);
end;
{$ENDREGION}

procedure TWebForm2.Page_Load(sender: System.Object; e: System.EventArgs);
begin
  // TODO: Put user code to initialize the page here
end;

function TWebForm2.VerificaSenha(aUsuario, aSenha: String): boolean;
var
sr: StreamReader;
aFileName: String;
Line: string;
FileLine: array of String;
Usuario: String;
Senha, aSenhaEncr: String;
begin
  Result := False;
  aFileName := Request.PhysicalApplicationPath + 'senhas.txt';
  if System.IO.File.Exists(aFileName) then
  begin
    sr := StreamReader.Create(System.IO.File.OpenRead(aFileName));
    try
      while sr.Peek > -1 do
      begin
        Line     := sr.ReadLine;           //Le uma linha
        FileLine := Line.Split(['=']); //Split -> Extrai valores separados por "="
        Usuario  := FileLine [0];
        Senha    := FileLine [1];
        if Usuario = aUsuario then
        begin
          aSenhaEncr := FormsAuthentication.HashPasswordForStoringInConfigFile(aSenha, 'md5');
          Result := (aSenhaEncr = Senha);
        end;
      end;
      finally 
      sr.Close;
      end;
  end;
end;

procedure TWebForm2.Button1_Click(sender: System.Object; e: System.EventArgs);
begin
  if VerificaSenha(Textbox1.Text,Textbox2.Text) then
  FormsAuthentication.RedirectFromLoginPage(Textbox1.Text,False)
  else
  LabelMsg.Text := 'Usuário ou senha inválidos';
end;

procedure TWebForm2.OnInit(e: EventArgs);
begin
  //
  // Required for Designer support
  //
  InitializeComponent;
  inherited OnInit(e);
end;

end.

