
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
  {$ENDREGION}
  strict private
    procedure Page_Load(sender: System.Object; e: System.EventArgs);
  strict protected
    Image1: System.Web.UI.WebControls.Image;
    Image2: System.Web.UI.WebControls.Image;
    Label1: System.Web.UI.WebControls.Label;
    Label2: System.Web.UI.WebControls.Label;
    Label3: System.Web.UI.WebControls.Label;
    Label4: System.Web.UI.WebControls.Label;
    Label5: System.Web.UI.WebControls.Label;
    DropDownList1: System.Web.UI.WebControls.DropDownList;
    RadioButtonSedan: System.Web.UI.WebControls.RadioButton;
    RadioButton1: System.Web.UI.WebControls.RadioButton;
    Label6: System.Web.UI.WebControls.Label;
    CheckBoxList1: System.Web.UI.WebControls.CheckBoxList;
    Label7: System.Web.UI.WebControls.Label;
    RadioButtonList1: System.Web.UI.WebControls.RadioButtonList;
    CheckBoxList2: System.Web.UI.WebControls.CheckBoxList;
    Button1: System.Web.UI.WebControls.Button;
    LabelPreco: System.Web.UI.WebControls.Label;
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
  Include(Self.Button1.Click, Self.Button1_Click);
  Include(Self.Load, Self.Page_Load);
end;
{$ENDREGION}

procedure TWebForm1.Page_Load(sender: System.Object; e: System.EventArgs);
begin
  // TODO: Put user code to initialize the page here
  if RadioButtonList1.Items[0] <> nil then
    RadioButtonList1.Items[0].Selected := true;
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
  preco : double;
  i,k : integer;
begin
  preco :=0;
  // Verifica Carro
  k := -1;
  for i := 0 to DropDownList1.Items.Count - 1 do
    if DropDownList1.Items[i].Selected then k := i;
  case k of
   0 : preco := preco + 25000;
   1 : preco := preco + 35000;
   2 : preco := preco + 45000;
   3 : preco := preco + 55000;
  end;
  // Verifica Tipo
  if RadioButtonSedan.Checked then preco := preco + 3000;
  // Verifica Motor
  if RadioButtonList1.Items[1].Selected then preco := preco + 3000;
  // Verifica Opcionais
  if CheckBoxList1.Items[0].Selected then preco := preco + 3000;
  if CheckBoxList1.Items[1].Selected then preco := preco + 1500;
  if CheckBoxList1.Items[2].Selected then preco := preco + 1000;
  if CheckBoxList1.Items[3].Selected then preco := preco + 300;
  // Verifica Acessrios
  if CheckBoxList2.Items[0].Selected then preco := preco + 1200;
  if CheckBoxList2.Items[1].Selected then preco := preco + 1000;
  if CheckBoxList2.Items[2].Selected then preco := preco + 1500;



  LabelPreco.Text := preco.ToString('c');
end;

end.

