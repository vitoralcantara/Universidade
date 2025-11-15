
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
  {$ENDREGION}
  strict private
    procedure Page_Load(sender: System.Object; e: System.EventArgs);
  strict protected
{$REGION 'Controls'}
    Label1: System.Web.UI.WebControls.Label;
    Label2: System.Web.UI.WebControls.Label;
    Label3: System.Web.UI.WebControls.Label;
    Label4: System.Web.UI.WebControls.Label;
    Label5: System.Web.UI.WebControls.Label;
    Label6: System.Web.UI.WebControls.Label;
    Label7: System.Web.UI.WebControls.Label;
    Label8: System.Web.UI.WebControls.Label;
    Label9: System.Web.UI.WebControls.Label;
    Label10: System.Web.UI.WebControls.Label;
    Label11: System.Web.UI.WebControls.Label;
    Label12: System.Web.UI.WebControls.Label;
    Label13: System.Web.UI.WebControls.Label;
    Label14: System.Web.UI.WebControls.Label;
    Label15: System.Web.UI.WebControls.Label;
    Label16: System.Web.UI.WebControls.Label;
    Label17: System.Web.UI.WebControls.Label;
    TextBox1: System.Web.UI.WebControls.TextBox;
    TextBox2: System.Web.UI.WebControls.TextBox;
    TextBox3: System.Web.UI.WebControls.TextBox;
    TextBox4: System.Web.UI.WebControls.TextBox;
    TextBox5: System.Web.UI.WebControls.TextBox;
    TextBox6: System.Web.UI.WebControls.TextBox;
    TextBox7: System.Web.UI.WebControls.TextBox;
    TextBox8: System.Web.UI.WebControls.TextBox;
    TextBox10: System.Web.UI.WebControls.TextBox;
    TextBox12: System.Web.UI.WebControls.TextBox;
    TextBox13: System.Web.UI.WebControls.TextBox;
    TextBox14: System.Web.UI.WebControls.TextBox;
    DropDownList1: System.Web.UI.WebControls.DropDownList;
    DropDownList2: System.Web.UI.WebControls.DropDownList;
    CheckBox1: System.Web.UI.WebControls.CheckBox;
{$ENDREGION}
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
  Include(Self.Load, Self.Page_Load);
end;
{$ENDREGION}

procedure TWebForm1.Page_Load(sender: System.Object; e: System.EventArgs);
begin
  if IsPostBack then
    Response.Redirect('ThankYouForm.aspx');
end;

procedure TWebForm1.OnInit(e: EventArgs);
begin
  //
  // Required for Designer support
  //
  InitializeComponent;
  inherited OnInit(e);
end;


end.

