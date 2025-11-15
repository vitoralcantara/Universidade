<%@ Page language="c#" Debug="true" Codebehind="WebForm1.pas" AutoEventWireup="false" Inherits="WebForm1.TWebForm1" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>
  <head><title></title>
	<link href="FormFormat.css" rel="stylesheet" type="text/css">
  </head>

  <body>
     <form runat="server">
      <p>
        <ASP:Label id="Label3" runat="server">Fonte Padrão</ASP:Label>
      </p>
      <p>
        <ASP:Label id="Label1" runat="server" font-bold="True" font-names="Bradley Hand ITC">Nome:</ASP:Label>
        <ASP:TextBox id="TextBox1" runat="server" bordercolor="#C0FFC0" backcolor="#FFFFC0"></ASP:TextBox>
      </p>
      <p>
        <ASP:Label id="Label5" runat="server" cssclass="Cabecalho">Sobrenome:</ASP:Label>
        <ASP:TextBox id="TextBox4" runat="server" cssclass="Cabecalho"></ASP:TextBox>
      </p>
      <p>
      <ASP:Label id="Label2" runat="server" cssclass="Texto">Endereço:</ASP:Label>
      <ASP:TextBox id="TextBox2" runat="server" cssclass="Texto"></ASP:TextBox></p>
      <p>
        <ASP:Label id="Label4" runat="server">Telefone:</ASP:Label>
        <ASP:TextBox id="TextBox3" runat="server"></ASP:TextBox>
      </p>
     </form>
  </body>
</html>
