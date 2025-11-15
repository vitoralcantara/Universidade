
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
    Label1: System.Web.UI.WebControls.Label;
    txbxFirstName: System.Web.UI.WebControls.TextBox;
    Label2: System.Web.UI.WebControls.Label;
    txbxLastName: System.Web.UI.WebControls.TextBox;
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
var
  UrlStr : string;
begin
  if IsPostBack then
  begin
    UrlStr := System.String.Format('WebForm2.aspx?Nome={0}&Sobrenome={1}',
      [txbxFirstName.Text, txbxLastName.Text]);
    Response.Redirect(UrlStr);
  end;
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

