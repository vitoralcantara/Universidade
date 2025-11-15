
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
    procedure OnInit(e: EventArgs); override;
  private
    { Private Declarations }
  public
    { Public Declarations }
  end;

implementation
uses System.Collections.Specialized;

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
  NameValCol: NameValueCollection;
  StrArray: array of String;
  i: integer;
begin
  // Client can request server information through the Request
  Response.Write(System.String.Format('Caminho da Aplicação: {0} <br>',
    [Request.ApplicationPath]));
  Response.Write(System.String.Format('Caminho do Arquivo: {0} <br>',
    [Request.FilePath]));
  Response.Write(System.String.Format('Informações do Caminho: {0} <br>',
    [Request.PathInfo]));
  Response.Write(System.String.Format('Caminho Físico: {0} <br>',
    [Request.PhysicalPath]));
  Response.Write(System.String.Format('Caminho Físico da Aplicação: {0} <br>',
    [Request.PhysicalApplicationPath]));
  Response.Write(System.String.Format('Endereço do Computador: {0} <br>',
    [Request.UserHostAddress]));
  Response.Write(System.String.Format('Nome do Computador: {0} <br>',
    [Request.UserHostName]));


  // Write HTTP Request information
  Response.Write(System.String.Format('Método HTTP: {0} <br>',
    [Request.HTTPMethod]));

  Response.Write('<br>');
  Response.Write('Informações do Cabeçalho<br>');

  NameValCol := Request.Headers;
  StrArray := NameValCol.AllKeys;
  for i := Low(StrArray) to High(StrArray) do
    Response.Write(System.String.Format('    {0} : {1} <br>',
      [StrArray[i], Request.Headers.Item[StrArray[i]]]));
  // Write browser information
  Response.Write('<br>');
  Response.Write('Informações do Browser <br>');
  Response.Write(System.String.Format('Tipo do Browser: {0}<br>',
    [Request.Browser.&Type.ToString]));
  Response.Write(System.String.Format('Versão do Browser: {0}<br>',
    [Request.Browser.Version]));
  Response.Write(System.String.Format('Plataforma: {0}<br>',
    [Request.Browser.Platform]));
  Response.Write(System.String.Format('Suporta Frames: {0}<br>',
    [Request.Browser.Frames.ToString]));

  // Write query information

  Response.Write('<br>');
  Response.Write(System.String.Format('String de Consulta: {0}<br>',
    [Request.QueryString]));
  Response.Write(System.String.Format('String de Consulta ''Name'': {0}<br>',
    [Request.QueryString['Name']]));
  Response.Write(System.String.Format('String de Consulta ''State'': {0}<br>',
    [Request.QueryString['State']]));
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

