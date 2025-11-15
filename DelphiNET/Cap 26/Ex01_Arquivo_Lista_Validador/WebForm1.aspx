<%@ Page Language="c#" Debug="true" codebehind="WebForm1.pas" autoeventwireup="false" Inherits="WebForm1.TWebForm1" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
    <title></title> 
    <meta content="Borland Package Library 7.1" name="GENERATOR" />
</head>
<body ms_positioning="GridLayout">
  <form runat="server">
    <p>
      <br>
      <br>&nbsp;
    </p>
    <table style="LEFT: 10px; WIDTH: 503px; TOP: 15px; HEIGHT: 723px" 
           cellspacing=0 cellpadding=0 width=503 align=left border=1>
      <tbody>
        <tr>
          <td valign=top align=left height=25>
            <asp:label id=Label4 runat="server">First Name</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox1 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label5 runat="server">Last Name</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox2 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label6 runat="server">Title</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox3 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label7 runat="server">EMail</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox4 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label8 runat="server">Company</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox5 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label9 runat="server">Address 1</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox6 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label10 runat="server">Address 2</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox7 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label11 runat="server">City</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox8 runat="server" width="322px" height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label12 runat="server">State/Province/Other</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:dropdownlist id=DropDownList2 runat="server" width="320px" 
                              height="22">
            </asp:dropdownlist>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label13 runat="server">Postal Code</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox10 runat="server" width="322px" 
                         height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label14 runat="server">Country</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:dropdownlist id=DropDownList1 runat="server" width="320px" 
                              height="22">
            </asp:dropdownlist>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label15 runat="server">Telephone</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox12 runat="server" width="322px" 
                         height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label16 runat="server">Fax</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox13 runat="server" width="322px" 
                         height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
            <asp:label id=Label17 runat="server">URL</asp:label>
          </td>
          <td valign=top align=left height=24>
            <asp:textbox id=TextBox14 runat="server" width="322px" 
                         height="24">
            </asp:textbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
          </td>
          <td valign=top align=left height=24>
            <asp:checkbox id=CheckBox1 runat="server" width="176px" 
                          height="20" text="Send Free Stuff">
            </asp:checkbox>
          </td>
        </tr>
        <tr>
          <td valign=top align=left height=24>
          </td>
          <td valign=top align=left height=24>
            <input type=submit value=Submit><input style="WIDTH: 57px; HEIGHT: 24px" type=reset size=21 value=Reset>
          </td>
        </tr>
      </tbody>
    </table>
    <asp:label id=Label1 
               style="Z-INDEX: 2; LEFT: 14px; POSITION: absolute; TOP: 14px" 
               runat="server">Welcome
        to the download page for XYZ Product    </asp:label>
    <asp:label id=Label2 
               style="Z-INDEX: 3; LEFT: 14px; POSITION: absolute; TOP: 38px" 
               runat="server">Please
        take a moment to provide us the following information. We will not release this information
        to any other party.    </asp:label>
    <asp:label id=Label3 
               style="Z-INDEX: 4; LEFT: 14px; POSITION: absolute; TOP: 62px" 
               runat="server">Upon
        completing the form, you will be emailed the download link.    </asp:label>
  </form>
</body>
</html>
