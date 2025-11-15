<%@ Page language="c#" Debug="true" Codebehind="WebForm1.pas" AutoEventWireup="false" Inherits="WebForm1.TWebForm1" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<html>
  <head>
    <title></title>
  </head>

  <body ms_positioning="GridLayout">
  <form runat="server">
    <asp:label id="Label1" 
               style="Z-INDEX: 1; LEFT: 14px; POSITION: absolute; TOP: -2px" 
               runat="server">Primeiro Nome</asp:label>
    <asp:textbox id="txbxFirstName" 
                 style="Z-INDEX: 2; LEFT: 14px; POSITION: absolute; TOP: 22px" 
                 runat="server">
    </asp:textbox>
    <asp:label id="Label2" 
               style="Z-INDEX: 3; LEFT: 14px; POSITION: absolute; TOP: 54px" 
               runat="server">Último Nome</asp:label>
    <asp:textbox id="txbxLastName" 
                 style="Z-INDEX: 4; LEFT: 14px; POSITION: absolute; TOP: 78px" 
                 runat="server">
    </asp:textbox>
    <input style="Z-INDEX: 5; LEFT: 14px; POSITION: absolute; TOP: 110px" 
           type="submit" value="Submeter">
  </form>
</body>
</html>
