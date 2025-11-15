
unit WebForm1;

interface

uses
  System.Collections, System.ComponentModel,
  System.Data, System.Drawing, System.Web, System.Web.SessionState,
  System.Web.UI, System.Web.UI.WebControls, System.Web.UI.HtmlControls;

type
  TWebForm1 = class(System.Web.UI.Page)
  {$REGION 'Designer Managed Code'}
  strict private
    procedure InitializeComponent;
    procedure Button1_Click(sender: System.Object; e: System.EventArgs);
    procedure Button2_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict private
    procedure Page_Load(sender: System.Object; e: System.EventArgs);
  strict protected
    Label1: System.Web.UI.WebControls.Label;
    BtnCriar: System.Web.UI.WebControls.Button;
    TextBox1: System.Web.UI.WebControls.TextBox;
    Label2: System.Web.UI.WebControls.Label;
    BtnExcluir: System.Web.UI.WebControls.Button;
    procedure OnInit(e: EventArgs); override;
  private
    { Private Declarations }
  public
    { Public Declarations }
  end;

implementation

{$REGION 'Designer Managed Code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure TWebForm1.InitializeComponent;
begin
  Include(Self.BtnCriar.Click, Self.Button1_Click);
  Include(Self.BtnExcluir.Click, Self.Button2_Click);
  Include(Self.Load, Self.Page_Load);
end;
{$ENDREGION}

procedure TWebForm1.Page_Load(sender: System.Object; e: System.EventArgs);
begin
  // Ler cookie
  if Request.Cookies['Ex2506_Cookie'] = nil then
    Label1.Visible := False
  else
    Label1.Text := System.String.Format('Olá {0}', Request.Cookies['Ex2506_Cookie'].Value);
end;

procedure TWebForm1.OnInit(e: EventArgs);
begin
  //
  // Required for Designer support
  //
  InitializeComponent;
  inherited OnInit(e);
end;

procedure TWebForm1.Button1_Click(sender: System.Object; e: System.EventArgs);
var
  hc: HttpCookie;
begin
  // Criar cookie
  hc := HttpCookie.Create('Ex2506_Cookie', TextBox1.Text);
  hc.Expires := DateTime.Now.AddMonths(1);
  Response.Cookies.Add(hc);
  //Label1.Visible := True;
  Label1.Text := System.String.Format('Olá {0}', TextBox1.Text);
end;

procedure TWebForm1.Button2_Click(sender: System.Object; e: System.EventArgs);
var
  hc: HttpCookie;
begin
  // Apagar cookie
  hc := Request.Cookies['Ex2506_Cookie'];
  hc.Values.Clear;
  Response.Cookies.Add(hc);
  //Label1.Visible := False;
end;


end.

