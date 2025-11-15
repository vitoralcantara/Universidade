<%@ Page language="c#" Debug="true" Codebehind="WebForm1.pas" AutoEventWireup="false" Inherits="WebForm1.TWebForm1" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>
  <head>
    <title></title>
  </head>

  <body>
     <form runat="server">
      <table cellspacing="1" cellpadding="1" width="750" border="0" height="150" bgcolor="palegoldenrod">
          <tr>
            <td style="HEIGHT: 101px">
			  <ASP:Image id="Image1" runat="server" imageurl="imagens/MeuCarango.jpg"></ASP:Image></td>
            <td style="WIDTH: 159px; HEIGHT: 101px">
              <p>
				<ASP:Label id="Label1" runat="server" font-bold="True" font-size="16pt" width="223px" forecolor="Navy">Meu Carango Veículos</ASP:Label>
			  </p>
			  <p>
				<ASP:Label id="Label2" runat="server" font-size="12pt" width="224px" forecolor="Navy">A sua loja de veículos na internet</ASP:Label>
			  </p></td>
			<td style="HEIGHT: 101px">
			  <ASP:Image id="Image2" runat="server" imageurl="imagens/BV.jpg"></ASP:Image></td>
		  </tr>
	  </table>
      <hr width="750" size="1" align="left">
      <table cellspacing="1" cellpadding="1" width="750" border="1">
          <tr>
            <td>
              <ASP:Label id="Label3" runat="server">Veículo</ASP:Label></td>
            <td>
              <ASP:Label id="Label5" runat="server">Tipo</ASP:Label></td>
            <td>
              <ASP:Label id="Label4" runat="server">Motorização</ASP:Label></td>
          </tr>
          <tr>
            <td>
              <ASP:DropDownList id="DropDownList1" runat="server" width="183px">
                <ASP:ListItem value="Celta (R$ 25.000,00)">Celta (R$ 25.000,00)</ASP:ListItem>
                <ASP:ListItem value="Corsa (R$ 35.000,00)">Corsa (R$ 35.000,00)</ASP:ListItem>
                <ASP:ListItem value="Astra (R$ 45.000,00)">Astra (R$ 45.000,00)</ASP:ListItem>
                <ASP:ListItem value="Vectra (R$ 55.000,00)">Vectra (R$ 55.000,00)</ASP:ListItem>
              </ASP:DropDownList></td>
            <td>
              <ASP:RadioButton id="RadioButton1" runat="server" checked="True" text="Hatch" groupname="Tipo"></ASP:RadioButton>
              <ASP:RadioButton id="RadioButtonSedan" runat="server" text="Sedan (+R$ 3.000,00)" groupname="Tipo"></ASP:RadioButton></td>
            <td>
              <ASP:RadioButtonList id="RadioButtonList1" runat="server">
                <ASP:ListItem value="1.4">1.4</ASP:ListItem>
                <ASP:ListItem value="2.0 (+R$ 3.000,00)">2.0 (+R$ 3.000,00)</ASP:ListItem>
              </ASP:RadioButtonList></td>
          </tr>
      </table>
      <hr width="750" size="1" align="left">
      <table cellspacing="1" cellpadding="1" width="750" border="1">
          <tr>
            <td>
              <ASP:Label id="Label6" runat="server">Opcionais</ASP:Label></td>
            <td>
              <ASP:Label id="Label7" runat="server">Acessórios</ASP:Label></td>
          </tr>
          <tr>
            <td>
              <ASP:CheckBoxList id="CheckBoxList1" runat="server">
                <ASP:ListItem value="Ar condicionado (R$ 3.000,00)">Ar condicionado (R$ 3.000,00)</ASP:ListItem>
                <ASP:ListItem value="Dire&#231;&#227;o Hidr&#225;ulica (R$ 1.500,00)">Dire&#231;&#227;o Hidr&#225;ulica (R$ 1.500,00)</ASP:ListItem>
                <ASP:ListItem value="Vidro El&#233;trico (R$ 1.000,00)">Vidro El&#233;trico (R$ 1.000,00)</ASP:ListItem>
                <ASP:ListItem value="Trava El&#233;trica (R$ 300,00)">Trava El&#233;trica (R$ 300,00)</ASP:ListItem>
              </ASP:CheckBoxList></td>
            <td>
              <ASP:CheckBoxList id="CheckBoxList2" runat="server">
                <ASP:ListItem value="Roda de Liga Leve (R$ 1.200,00)">Roda de Liga Leve (R$ 1.200,00)</ASP:ListItem>
                <ASP:ListItem value="Som (R$ 1.000,00)">Som (R$ 1.000,00)</ASP:ListItem>
                <ASP:ListItem value="Aerof&#243;lio (R$ 1.500,00)">Aerof&#243;lio (R$ 1.500,00)</ASP:ListItem>
              </ASP:CheckBoxList></td>
          </tr>
      </table>
      <hr width="750" size="1" align="left">
      <table cellspacing="1" cellpadding="1" width="750" border="1">
          <tr>
            <td style="WIDTH: 366px">
              <ASP:Button id="Button1" runat="server" text="Consultar"></ASP:Button></td>
            <td>
              <ASP:Label id="LabelPreco" runat="server">Preço</ASP:Label></td>
          </tr>
      </table>
     </form>
  </body>
</html>
