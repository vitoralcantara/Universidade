<%@ Page language="c#" Debug="true" Codebehind="WebForm1.pas" AutoEventWireup="false" Inherits="WebForm1.TWebForm1" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<html>
  <head>
    <title></title>
  </head>

  <body ms_positioning="GridLayout">
  <form runat="server">
    <asp:label id="Label1" 
               style="Z-INDEX: 2; LEFT: 6px; POSITION: absolute; TOP: 6px" 
               runat="server">Mensagem de Entrada</asp:label>
    <asp:textbox id="TextBox1" 
                 style="Z-INDEX: 4; LEFT: 118px; POSITION: absolute; TOP: 46px" 
                 runat="server">
    </asp:textbox>
    <asp:button id="Button1" 
                style="Z-INDEX: 3; LEFT: 22px; POSITION: absolute; TOP: 102px" 
                runat="server" text="Criar Cookie">
    </asp:button>
    <asp:label id="Label2" 
               style="Z-INDEX: 5; LEFT: 14px; POSITION: absolute; TOP: 46px" 
               runat="server">Digite seu nome</asp:label>
    <asp:button id="Button2" 
                style="Z-INDEX: 3; LEFT: 23px; POSITION: absolute; TOP: 153px" 
                runat="server" text="Excluir Cookie" width="101px">
    </asp:button>
  </form>
</body>
</html>
