
unit WebForm1;

interface

uses
  System.Collections, System.ComponentModel,
  System.Data, System.Drawing, System.Web, System.Web.SessionState,
  System.Web.UI, System.Web.UI.WebControls, System.Web.UI.HtmlControls,
  System.Globalization;

type
  TWebForm1 = class(System.Web.UI.Page)
  {$REGION 'Designer Managed Code'}
  strict private
    procedure InitializeComponent;
    procedure Button1_Click(sender: System.Object; e: System.EventArgs);
    procedure Button11_Click(sender: System.Object; e: System.EventArgs);
    procedure Button15_Click(sender: System.Object; e: System.EventArgs);
    procedure Button16_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict private
    procedure Page_Load(sender: System.Object; e: System.EventArgs);
  strict protected
    Label1: System.Web.UI.WebControls.Label;
    Label2: System.Web.UI.WebControls.Label;
    Label3: System.Web.UI.WebControls.Label;
    TextBox1: System.Web.UI.WebControls.TextBox;
    TextBox2: System.Web.UI.WebControls.TextBox;
    TextBox3: System.Web.UI.WebControls.TextBox;
    LabelOperacao: System.Web.UI.WebControls.Label;
    Label5: System.Web.UI.WebControls.Label;
    Button1: System.Web.UI.WebControls.Button;
    Button2: System.Web.UI.WebControls.Button;
    Button3: System.Web.UI.WebControls.Button;
    Button4: System.Web.UI.WebControls.Button;
    Button5: System.Web.UI.WebControls.Button;
    Button6: System.Web.UI.WebControls.Button;
    Button7: System.Web.UI.WebControls.Button;
    Button8: System.Web.UI.WebControls.Button;
    Button9: System.Web.UI.WebControls.Button;
    Button10: System.Web.UI.WebControls.Button;
    Button11: System.Web.UI.WebControls.Button;
    Button12: System.Web.UI.WebControls.Button;
    Button13: System.Web.UI.WebControls.Button;
    Button14: System.Web.UI.WebControls.Button;
    Button15: System.Web.UI.WebControls.Button;
    Button16: System.Web.UI.WebControls.Button;
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
  Include(Self.Button8.Click, Self.Button1_Click);
  Include(Self.Button9.Click, Self.Button1_Click);
  Include(Self.Button10.Click, Self.Button1_Click);
  Include(Self.Button11.Click, Self.Button11_Click);
  Include(Self.Button5.Click, Self.Button1_Click);
  Include(Self.Button6.Click, Self.Button1_Click);
  Include(Self.Button7.Click, Self.Button1_Click);
  Include(Self.Button12.Click, Self.Button11_Click);
  Include(Self.Button2.Click, Self.Button1_Click);
  Include(Self.Button3.Click, Self.Button1_Click);
  Include(Self.Button4.Click, Self.Button1_Click);
  Include(Self.Button13.Click, Self.Button11_Click);
  Include(Self.Button1.Click, Self.Button1_Click);
  Include(Self.Button16.Click, Self.Button16_Click);
  Include(Self.Button15.Click, Self.Button15_Click);
  Include(Self.Button14.Click, Self.Button11_Click);
  Include(Self.Load, Self.Page_Load);
end;
{$ENDREGION}

procedure TWebForm1.Page_Load(sender: System.Object; e: System.EventArgs);
begin
  // TODO: Put user code to initialize the page here
  Label1.Text := DateTime.Now.ToString('t',DateTimeFormatInfo.InvariantInfo);

  if not IsPostBack then
    Label2.Text := DateTime.Now.ToString('t',DateTimeFormatInfo.InvariantInfo);
end;

procedure TWebForm1.OnInit(e: EventArgs);
begin
  //
  // Required for Designer support
  //
  InitializeComponent;
  inherited OnInit(e);
end;

procedure TWebForm1.Button16_Click(sender: System.Object; e: System.EventArgs);
begin
  TextBox1.Text := '';
  TextBox2.Text := '';
  TextBox3.Text := '';
  LabelOperacao.Text := '';
end;

procedure TWebForm1.Button15_Click(sender: System.Object; e: System.EventArgs);
var
  a , b, c : integer;
begin
  if LabelOperacao.Text <> '' then
  begin
    a := Convert.ToInt32(TextBox1.Text);
    b := Convert.ToInt32(TextBox2.Text);
    case LabelOperacao.Text[1] of
      '+' : c := a + b;
      '-' : c := a - b;
      '*' : c := a * b;
      '/' : c := a div b;
      else c := 0;
    end;
    TextBox3.Text := c.ToString;
  end;
end;

procedure TWebForm1.Button11_Click(sender: System.Object; e: System.EventArgs);
begin
  LabelOperacao.Text := (sender as Button).Text;
end;

procedure TWebForm1.Button1_Click(sender: System.Object; e: System.EventArgs);
begin
  if LabelOperacao.Text = '' then
    TextBox1.Text := TextBox1.Text + (sender as Button).Text
  else
    TextBox2.Text := TextBox2.Text + (sender as Button).Text;
end;

end.

