<%@ Page language="c#" Debug="true" Codebehind="WebForm1.pas" AutoEventWireup="false" Inherits="WebForm1.TWebForm1" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>
  <head>
    <title></title>
  </head>

  <body>
     <form runat="server">
      <table cellspacing="0" cellpadding="0" width="600" border="0">
          <tr>
            <td>
              <ASP:Label id="Label3" runat="server" font-bold="True" backcolor="White" bordercolor="White" font-names="Bookman Old Style" forecolor="Blue">Calculadora</ASP:Label></td>
            <td>
              <ASP:Label id="Label1" runat="server">hora1</ASP:Label></td>
            <td>
              <ASP:Label id="Label2" runat="server">hora2</ASP:Label></td>
          </tr>
      </table>
      <hr width="100%" size="1">
      <table cellspacing="1" cellpadding="1" width="200" border="0">
          <tr>
            <td></td>
            <td>
              <ASP:TextBox id="TextBox1" runat="server" width="150px"></ASP:TextBox></td>
          </tr>
          <tr>
            <td>
              <ASP:Label id="LabelOperacao" runat="server"></ASP:Label></td>
            <td>
              <ASP:TextBox id="TextBox2" runat="server" width="150px"></ASP:TextBox></td>
          </tr>
          <tr>
            <td>
              <ASP:Label id="Label5" runat="server">=</ASP:Label></td>
            <td>
              <ASP:TextBox id="TextBox3" runat="server" width="150px"></ASP:TextBox></td>
          </tr>
          <tr>
            <td></td>
            <td>
              <table cellspacing="1" cellpadding="1" width="150" border="0">
                  <tr>
                    <td>
                      <ASP:Button id="Button8" runat="server" text="7"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button9" runat="server" text="8"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button10" runat="server" text="9"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button11" runat="server" text="+"></ASP:Button></td>
                  </tr>
                  <tr>
                    <td>
                      <ASP:Button id="Button5" runat="server" text="4"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button6" runat="server" text="5"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button7" runat="server" text="6"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button12" runat="server" text="-"></ASP:Button></td>
                  </tr>
                  <tr>
                    <td>
                      <ASP:Button id="Button2" runat="server" text="1"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button3" runat="server" text="2"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button4" runat="server" text="3"></ASP:Button></td>
                    <td>
                      <ASP:Button id="Button13" runat="server" text="*"></ASP:Button></td>
                  </tr>
                  <tr>
                    <td style="HEIGHT: 15px">
                      <ASP:Button id="Button1" runat="server" text="0"></ASP:Button></td>
                    <td style="HEIGHT: 15px">
                      <ASP:Button id="Button16" runat="server" text="C"></ASP:Button></td>
                    <td style="HEIGHT: 15px">
                      <ASP:Button id="Button15" runat="server" text="="></ASP:Button></td>
                    <td style="HEIGHT: 15px">
                      <ASP:Button id="Button14" runat="server" text="/"></ASP:Button></td>
                  </tr>
              </table></td>
          </tr>
          <tr>
            <td></td>
            <td></td>
          </tr>
      </table>
     </form>
  </body>
</html>
