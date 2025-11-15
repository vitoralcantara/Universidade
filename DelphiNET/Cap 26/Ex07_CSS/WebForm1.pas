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
    TextBox1: System.Web.UI.WebControls.TextBox;
    Label2: System.Web.UI.WebControls.Label;
    TextBox2: System.Web.UI.WebControls.TextBox;
    Label3: System.Web.UI.WebControls.Label;
    TextBox3: System.Web.UI.WebControls.TextBox;
    Label4: System.Web.UI.WebControls.Label;
    Label5: System.Web.UI.WebControls.Label;
    TextBox4: System.Web.UI.WebControls.TextBox;
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
  MyStyle: Style;
begin
  MyStyle := Style.Create;
  MyStyle.BackColor := Color.Aqua;
  MyStyle.ForeColor := Color.Yellow;
  MyStyle.BorderColor := Color.BlueViolet;
  MyStyle.BorderWidth := &Unit.Create(3);
  MyStyle.Font.Name := 'Corrier New';
  Label4.ApplyStyle(MyStyle);
  TextBox3.ApplyStyle(MyStyle);
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

