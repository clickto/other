//==���￪ʼ Ϊ��ʵ��������ʾ������ģ�Ͷ�������ʵ�������Ĵ���

//ͼƬ·������
//var StrLeafImage = "<img src=\"/stPortal/include/tree/images/line.gif\" border=0>";
//var StrLeafImage1 = "<img src=\"/stPortal/include/tree/images/line1.gif\" border=0>";
//var StrEmptyImage = "<img src=\"/stPortal/include/tree/images/dot.gif\" border=0 style=\"width:15px\">";

//var StrCloseImage = "<img src=\"/stPortal/include/tree/images/add.gif\" border=\"0\">";
//var StrExpandImage = "<img src=\"/stPortal/include/tree/images/sub.gif\" border=\"0\">";

//var StrCloseImageTop = "<img src=\"/stPortal/include/tree/images/top.gif\" border=\"0\">";
//var StrExpandImageTop = "<img src=\"/stPortal/include/tree/images/-top.gif\" border=\"0\">";
//var StrCloseImageBottom = "<img src=\"/stPortal/include/tree/images/bottom.gif\" border=\"0\">";
//var StrExpandImageBottom = "<img src=\"/stPortal/include/tree/images/-bottom.gif\" border=\"0\">";
//var StrCloseImageLeft = "<img src=\"/stPortal/include/tree/images/left.gif\" border=\"0\">";
//var StrExpandImageLeft = "<img src=\"/stPortal/include/tree/images/-left.gif\" border=\"0\">";

//var StrExpandImage2 = "<img src=\"/stPortal/include/tree/images/open.gif\" border=\"0\">";
//var StrCloseImage2 = "<img src=\"/stPortal/include/tree/images/close.gif\" border=\"0\">";
//var StrBackground="/stPortal/include/tree/images/line-bg.gif";

//��ǰ�ڵ��ֵ
var StrLastNode="";
var sMsg="";
var sToolBar;
//--�������-------------------------------------------------------------

function tNode(a_NodeName,a_ParaName,a_ParaNode,a_tAry,a_Tree)
{
	this.nodeName = a_NodeName; //������
	this.paraName = a_ParaName; //��㸸����
	this.paraNode = a_ParaNode; //���ĸ����
	this.array = a_tAry; //����������������������ȣ�����һ��tArray��ǿ��������
	this.tree = a_Tree; //������ڵ�tTree��������
	this.children = new tArray(); //���Ķ��Ӽ��ϣ���һ��tArray�����

	this.Update = tNodeUpdate; //����һ�����ķ���
	this.toString = tNodetoString; //Debug�õĴ�������Ϣ�ķ���
	this.isLeaf = tNodeisLeaf; //�жϱ�����Ƿ�Ҷ�ӽ��ķ���
	this.Layer = tNodeLayer; //���ر���������еĵڼ��㣬��0��ʼ����
	this.Index = tNodeIndex; //������ͬһ���б�����ǵڼ�����㣬��0��ʼ����
	this.BrotherCount = tNodeBrotherCount; //����ͬһ�����ж��ٸ��ֵܽ�㣬�����Լ�
	this.Clone = tNodeClone; //��¡�����

	//�������ͨ�õģ��������Ϊ��ʵ��������ʾ��д��
	this.RenderTable = tNodeRenderTable;
	this.HideTable = tNodeHideTable;
	this.ExpandImage = tNodeExpandImage;
	this.OnClick = tNodeOnClick;
	this.OnContextMenu = tNodeOnContextMenu;
	this.VLine = tNodeVLine;
	this.AdjustPic = tNodeAdjustPic;
    this.ExpandNode = tExpandNode;
	this.onmouseupex = tNodeOnMouseUp;
	this.onmousedownex = tNodeOnMouseDown;
}


function tNodeClone()
{
	var l_node = new tNode(this.nodeName,this.paraName,this.paraNode,this.array,this.tree);
	l_node.children = this.children;
	return l_node;
}

function tNodeOnMouseDown()
{
	this.tree.OnMouseDownNode = this;
}

function tNodeOnMouseOver()
{
	return;
	self.status += this.nodeName + ':';
	if ( this.tree.OnMouseOverNode != null )
		return;
	this.tree.OnMouseOverNode = this;
}

function tNodeOnMouseOut()
{
	this.tree.OnMouseOverNode = null;
}

/*
function tNodeVLine()
���ܣ�����һ������ǰ��Ӧ�÷�ʲô����style
���룺
�����
*/
function tNodeVLine()
{
	var l_td = document.all.item(this.nodeName + "_vline");
	if ( l_td == null ){
		return;
	}
	if ( ! ( this.paraNode != null
			&& ( parseInt( this.paraNode.Index() ) == parseInt( this.paraNode.BrotherCount() -1 ) )
			)
		)
	{
		l_td.style.backgroundPositionX = "4px";
		l_td.style.backgroundImage = "url("+StrBackground+")";
		l_td.style.backgroundRepeat = "repeat-y";
	}else{
		l_td.style.backgroundImage = "";
		l_td.style.backgroundRepeat = "";
		}
}

//�������ļӼ�š����ߡ��ļ���ͼƬ
function tNodeAdjustPic(a_expand)
{
	var l_tb = document.all.item(this.nodeName + '_childrentable');
        //�����Ҷ�ӽڵ�ͷ��ء�
        if(l_tb==null) return;
	var l_expand = document.all.item(this.nodeName + "_expand");
	l_dis = l_tb.style.display;

	l_folder = document.all.item(this.nodeName + '_folder');

	l_expand.style.cursor = ( this.children.count > 0 ) ? "hand" : "";

	if ( l_dis == '' && this.children.count > 0 )
	{
		l_expand.innerHTML = this.ExpandImage(1);
		if (this.array.Find('ExpandImage') != null ) //������Զ����չ��ͼƬ����
			l_folder.innerHTML = this.array.Find('ExpandImage');
		else //������ȱʡ��չ��ͼƬ
			l_folder.innerHTML = StrExpandImage2;
	}else{
		l_expand.innerHTML = this.ExpandImage(0);
		if (this.array.Find('CloseImage') != null ) //������Զ��������ͼƬ����
			l_folder.innerHTML = this.array.Find('CloseImage');
		else //������ȱʡ������ͼƬ
			{
				if (this.array.Find("cate_type")=="0")
    			{l_folder.innerHTML = StrCloseImage2;}
    			else
    			{l_folder.innerHTML = StrFucntionImage;}
			}
	}

	this.VLine();
}

//�����Ҽ��˵��¼�
function tNodeOnContextMenu()
{
  /*
   popupoptions = [
   						new ContextItem("ˢ�±�ҳ",function(){window.location.reload();}),
						new ContextItem("Disabled Item",null,true),
						new ContextSeperator(),
						new ContextItem("��ӡ",function(){window.print()}),
						new ContextItem("�鿴������",function(){tNodeOnClick();document.body.focus();}),
						new ContextSeperator(),
   						new ContextItem("����",function(){alert('����');document.body.focus();})
   				  ]
   ContextMenu.display(popupoptions)*/
}

//����OnClick�¼�
function tNodeOnClick()
{
	var elem = window.event.srcElement;
	var strNodeID;

	strNodeID=elem.id;

	SetDBFocus(strNodeID);

}
/*
function tNodeHideTable()
���ܣ��������һ�����ǰ��ļӺš����ŵ��¼�
���룺
�����
*/
function tNodeHideTable()
{
	var l_tb,l_dis,l_expand,l_folder;
  l_tb = document.all.item(this.nodeName + '_childrentable');
  l_dis = l_tb.style.display;
  l_expand = document.all.item(this.nodeName + '_expand');
  l_folder = document.all.item(this.nodeName + '_folder');
  if ( l_dis == 'none' )
  {
    this.ExpandNode();
    l_tb.style.display = '';
    l_expand.innerHTML = this.ExpandImage(1,0);
    l_folder.innerHTML = StrExpandImage2;
  }else{
    l_tb.style.display = 'none';
    l_expand.innerHTML = this.ExpandImage(0,0);
    if (this.array.Find("cate_type")=="0")
    {l_folder.innerHTML = StrCloseImage2;}
    else
    {l_folder.innerHTML = StrFucntionImage;}
  }
}

/*
function tNodeExpandImage(a_expand)
���ܣ��ж�һ������ǰ��Ӧ�÷��ĸ��Ӻš����ŵ�ͼƬ
���룺
	a_expand��������Ƿ�չ��״̬��1��չ����0������
�����
	Ӧ�÷ŵ�ͼƬ���ַ���
*/
function tNodeExpandImage(a_expand)
{
	//�Ӽ���ͼƬ
	if ( this.children.count > 0 ) //��Ҷ�ӽ��
	{
		if ( this.Layer() == 0 && this.BrotherCount() == 1 ) //��һ����ֻ��һ�����
			return (a_expand == 1) ? StrExpandImage : StrCloseImage;
		else if ( this.Index() == 0 && this.Layer() == 0 ) //��һ��ĵ�һ�����
			return (a_expand == 1) ? StrExpandImageTop : StrCloseImageTop;
		else if ( this.Index() == this.BrotherCount() - 1 ) //һ���е����һ�����
			return (a_expand == 1) ? StrExpandImageBottom : StrCloseImageBottom;
		else
			return (a_expand == 1) ? StrExpandImageLeft : StrCloseImageLeft; //һ��Ľ��
	}else{ //Ҷ�ӽ��
		if ( this.Index() == this.BrotherCount() - 1 ) //һ���е����һ�����
			return StrLeafImage1;
		else
			return StrLeafImage; //��һ���е����һ�����
	}
}


function tNodeOnMouseUp()
{
	var el,tar, oTar, el_tr, tar_tr, tar_el, l_table, el_tr_0, l_node;

	//�ѱ�����λ�û�ԭ
	el = document.all.item(this.nodeName + '_Move'); //�õ�������tr���ƶ�Div
	el.style['z-index'] = 0;
	el.style.pixelLeft = 0;
	el.style.pixelTop = 0;

	if ( this.paraNode == null || this.paraNode.children.count < 2 ) //���������Ǹ������߱����û���ֵܽ����˳�
		return;

	tar_el = document.elementFromPoint(event.clientX ,event.clientY); //��ǰ���λ��htmlԪ��
	tar = getReal(tar_el); //Ŀ����Div
	if ( tar == null || tar.nodeName == null ) //���Ŀ�������Ϣ������˳�
		return;

	el_tr = document.all.item(this.nodeName + '_Tr'); //�����Tr
	tar_tr = document.all.item(tar.nodeName + '_Tr'); //Ŀ����Tr
	oTar = this.tree.Find(tar.nodeName); //Ŀ�������
	if ( oTar != null //Ŀ������tNode���
	 && oTar.paraNode != null //Ŀ���㲻�Ǹ����
	 && tar.nodeName != this.nodeName //Ŀ���㲻�Ǳ����
	 && this.children.Find(tar.nodeName) == null //Ŀ���㲻�Ǳ����Ķ���
	 && this.paraNode.nodeName != tar.nodeName //Ŀ���㲻�Ǳ����ĸ���
	 && this.paraNode.nodeName == oTar.paraNode.nodeName //Ŀ����ͱ�������ֵܽ��
	)
	{
		el_tr_0 = document.createElement("TR");
		l_table = el_tr.parentElement;
		l_table.insertBefore(el_tr_0,tar_tr);
		el_tr.swapNode(el_tr_0);
		el_tr_0.removeNode();

		l_node = this.Clone();
		rmv = l_node.tree.Remove(this.nodeName, 1); //ֻȥ������㣬��ȥ�����ӽ��
		ins = l_node.tree.insertBefore(tar.nodeName,l_node.nodeName,l_node);
		ins2 = '';
		if ( l_node.paraNode != null )
		{
			ins2 = l_node.paraNode.children.insertBefore(tar.nodeName,l_node.nodeName,l_node);
		}
		l_node.tree.AdjustPic();
		//�޸ĸ��ڵ������ݿ��еĴ���
		//1�����ȵõ����ڵ�ĸ��ڵ㣬���Ը��ڵ��childern����ѭ���õ����ڵ��˳��
		ChangeNodeIndex(l_node);
	}
}
/*
function tNodeRenderTable()
���ܣ�����һ�����Ľ��棬����html�ַ���
���룺
�����
	������html�ַ���
*/
function tNodeRenderTable()
{
	var l_name,l_node,l_return = "";
	l_return += "<tr id='" + this.nodeName + "_tr'>\n";

	//��������
	l_node = this.paraNode;
	if ( l_node != null )
	{
		l_return += "<td id='" + this.nodeName + "_vline' style=\"width:18px;";
	if ( ! ( this.paraNode != null
			&& this.paraNode.Index() == ( this.paraNode.BrotherCount() -1 )
			)
		)
	{
		l_return += "background-position-x:4px;background-repeat:repeat-y;background-image:url("+StrBackground+");";
		l_return += "\">";
/*		l_return += this.nodeName + ';' + this.BrotherCount()
					 + ';' + this.Index()
					 + ';' + this.paraNode.BrotherCount()
					 + ';' + this.paraNode.Index();
*/		l_return +="&nbsp;</td>\n";
	}
	else
	{
		l_return += "\">&nbsp;</td>\n";
	}
	}

	l_return += "<td style=\"width:4px\"></td>\n";

	l_return += "<td>\n";

	l_return += "<table border=0 cellspacing=0 cellpadding=0>";
	l_return += "<tr >";

	l_return += "<td style=\"width:0%\">";
	l_return += "<span id='" + this.nodeName + "_expand'";
	l_return += " onclick=\"javascript:oTree.Find('" + this.nodeName + "').HideTable();\"";

	//�Ӽ���ͼƬ
	if ( this.children.count > 0 ) //��Ҷ�ӽ��
	{
		l_return += " style=\"cursor:hand;width:18px\">";
	}else{ //Ҷ�ӽ��
		l_return += " style=\"width:18px\">";
	}
	l_return += this.ExpandImage(this.tree.ShowOnRender);
	l_return += "</span>";
	l_return += "</td >";

	l_return += "<td style=\"width:0%\">";

	//�ļ���ͼƬ
	l_return += "<span id='" + this.nodeName + "_folder'>";
	if (this.array.Find('cate_type')==0)
	{	l_return += StrCloseImage2;}
	else
	{	l_return += StrFucntionImage;}
	l_return += "</span>";

	l_return += "</td>";
	l_return += "<td align=left>";

	//���������
	l_return += "<div nodeName=\"" + this.nodeName + "\"";
	l_return += " onmousedownex=\"javascript:oTree.Find('" + this.nodeName + "').onmousedownex();\"";
//	l_return += " onmouseout=\"javascript:oTree.Find('" + this.nodeName + "').onmouseoutex();\"";
//	l_return += " onmouseover=\"javascript:oTree.Find('" + this.nodeName + "').onmouseoverex();\"";
	l_return += " onmouseupex=\"javascript:oTree.Find('" + this.nodeName + "').onmouseupex();\"";
	l_return += " id='" + this.nodeName + "_Move'";
	l_return += " class=moveme style=\"position:relative;\">";
	l_return += "<input id='" + this.nodeName + "_Value' type=text readonly style=\"height:13px;cursor:hand;border:0\"";
	l_return += " id='" + this.nodeName + "_desc'";
	l_return += " onclick=\"javascript:oTree.Find('" + this.nodeName + "').OnClick();\"";
	l_return += " oncontextmenu=\"javascript:oTree.Find('" + this.nodeName + "').OnContextMenu()\"";
	l_return += " class=\"node\"";
//	l_return += " onmouseout=\"javascript:oTree.Find('" + this.nodeName + "').onmouseoutex();\"";
//	l_return += " onmouseover=\"javascript:oTree.Find('" + this.nodeName + "').onmouseoverex();\"";
	l_return += " value=\"";
	l_return += this.array.Find('cate_desc');
	l_return += "\"></input>";
	l_return += "</div>";

	l_return += "</td>";

	l_return += "</tr>";

	//�ӷ����table
	l_return += "<tr>";

	l_return += "<td colspan=3>";
	l_return += "<table border=0 cellspacing=0 cellpadding=0 width=\"100%\"";
	if ( this.tree.ShowOnRender == 0 )
		l_return += " style=\"display:none\"";
	l_return += " id='" + this.nodeName + "_childrentable'>\n";
    if(this.tree.ShowOnRender==1 && this.Layer()==0){
      for ( l_name in this.children.nodes )
      {
        l_node = this.children.nodes[l_name];
        l_return += l_node.RenderTable();
      }
    }
	l_return += "</table>\n";
	l_return += "</td>";

	l_return += "</tr>";
	l_return += "</table>";

	//����
	l_return += "</td>\n";
	l_return += "</tr>\n";
	return l_return;
}

//--����-------------------------------------------------------------

function tTree() //��������
{
	this.nodes = new tArray(); //���Ľ�㼯��
	this.count = tTreeCount; //���Ľ�����
	this.Add = tAddNode; //����һ�����ķ���
	this.Find = tFindNode; //���ݴ����ҵ�һ�����ķ���
	this.Remove = tRemoveNode; //ɾ��һ�����ķ���
	this.Update = tUpdateNode; //����һ�����ķ���
	this.insertBefore = tInsertBefore; //����һ�����
	this.toString = tTreetoString; //����Debugʱ������������Ϣ�ķ���

    //�������ͨ�õģ��������Ϊ��ʵ��������ʾ��д��
	this.ShowOnRender = 0; //ȱʡ���Ŀ�ʼ״̬�ǲ�չ����
	this.RenderTable = tRenderTable;
	this.AdjustPic = tAdjustPic;
	this.UpdateEx = tUpdateNodeEx;
    this.ExpandNode = tExpandNode;
}
//modified by AlexZeng
/**
 * �����ӽڵ�
 * @return
 */
function tExpandNode(){
  var l_return = "";
  var l_ctbl = document.all.item(this.nodeName + '_childrentable');
  if(!this.isRender){
    l_return += "<table border=0 cellspacing=0 cellpadding=0 width=\"100%\"";
    l_return += " id='" + this.nodeName + "_childrentable'>\n";

    for ( l_name in this.children.nodes )
    {
            l_node = this.children.nodes[l_name];
            l_return += l_node.RenderTable();
    }

    l_return += "</table>\n";

    l_ctbl.outerHTML = l_return;
    l_ctbl.style.display = '';
    this.isRender = true;
  }
}
function tInsertBefore(a_NodeName1,a_NodeName2,a_node)
{
	return this.nodes.insertBefore(a_NodeName1,a_NodeName2,a_node);
}

function tUpdateNodeEx(a_nodeName,a_paraName,a_ary)
{
	var l_tAry = new tArray(), l_s;
	for ( l_s in a_ary )
	{
		l_tAry.Add( l_s, a_ary[l_s] );
	}
	this.Update(a_nodeName,a_paraName,l_tAry);
}

function tAdjustPic()
{
	var l_node;
	for ( l_node in this.nodes.nodes )
	{
		this.nodes.Find(l_node).AdjustPic();
	}
}

/*
function tRenderTable(a_ShowOnRender)
���ܣ�����һ�����Ľ��棬����html�ַ���
���룺
	a_ShowOnRender���Ƿ�չ����������1��չ����0������
�����
	������html�ַ���
*/
function tRenderTable(a_ShowOnRender)
{
  var l_name,l_node,l_return = "";
  this.ShowOnRender = a_ShowOnRender;
  this.tTreeTable = 'tTreeTable';
  while ( document.all.item(this.tTreeTable) != null )
          this.tTreeTable += '0';
  l_return += "<table ID=\"" + this.tTreeTable + "\" border=0 cellspacing=0 cellpadding=0>\n";
  for ( l_name in this.nodes.nodes )
  {
          l_node = this.nodes.nodes[l_name];
          if ( l_node.paraNode != null )
                  continue;
          l_return += l_node.RenderTable();
  }
  l_return += "</table>\n";
  return l_return;
}
//ˢ��ҳ��
function RefreshPage()
{
	//ShowTree();
	document.all.item('divRender').innerHTML = oTree.RenderTable(0);
	//չ�����ĵ�һ��
	oNode = oTree.Find('0');
	if (oNode!=null){
		oNode.HideTable();
	}
	StrLastNode="";
}

function GetTD1(oNode,oTr)
{
	var l_name,l_node,l_return = "";
	var oTD,l_HTML;

	//��������
	l_node = oNode.paraNode;
	if ( l_node != null )
	{
		//����һ��TD
		oTD = oTr.insertCell();
		oTD.width = "18px";
		if ( document.all.item(oNode.nodeName + "_vline") != null )
		{
			alert(document.all.item(oNode.nodeName + "_vline").outerHTML);
		}
		oTD.id = oNode.nodeName + "_vline";
	}

	oTD=oTr.insertCell();

	oTD.width="4px";
	oTD.innerHTML="&nbsp;"

	oTD=oTr.insertCell();

	l_HTML = GetTD3(oNode);
	oTD.innerHTML=l_HTML;
}

function GetTD3(oNode)
{
	var l_name,l_node,l_return="";

	l_return += "<table border=0 cellspacing=0 cellpadding=0>";
	l_return += "<tr >";

	l_return += "<td style=\"width:0%\">";
	l_return += "<span  id='" + oNode.nodeName + "_expand'";
	l_return += " onclick=\"javascript:oTree.Find('" + oNode.nodeName + "').HideTable();\"";

	//�Ӽ���ͼƬ
	if ( oNode.children.count > 0 ) //��Ҷ�ӽ��
	{
		l_return += " style=\"cursor:hand;width:18px\">";
	}else{ //Ҷ�ӽ��
		l_return += " style=\"width:0%\">";
	}
	l_return += oNode.ExpandImage(0);
	l_return += "</span>";
	l_return += "</td >";

	l_return += "<td style=\"width:0%\">";

	//�ļ���ͼƬ
	l_return += "<span id='" + oNode.nodeName + "_folder'>";
	if (oNode.array.Find('cate_type')==0)
	{	l_return += StrCloseImage2;}
	else
	{	l_return += StrFucntionImage;}
	l_return += "</span>";

	l_return += "</td>";
	l_return += "<td align=left>";

	//���������
	l_return += "<div nodeName=\"" + oNode.nodeName + "\"";
	l_return += " onmousedownex=\"javascript:oTree.Find('" + oNode.nodeName + "').onmousedownex();\"";
//	l_return += " onmouseout=\"javascript:oTree.Find('" + oNode.nodeName + "').onmouseoutex();\"";
//	l_return += " onmouseover=\"javascript:oTree.Find('" + oNode.nodeName + "').onmouseoverex();\"";
	l_return += " onmouseupex=\"javascript:oTree.Find('" + oNode.nodeName + "').onmouseupex();\"";
	l_return += " id='" + oNode.nodeName + "_Move'";
	l_return += " class=moveme style=\"position:relative;\">";
	l_return += "<input id='" + oNode.nodeName + "_Value' type=text readonly style=\"height:13px;cursor:hand;border:0\"";
	l_return += " id='" + oNode.nodeName + "_desc'";
	l_return += " onclick=\"javascript:oTree.Find('" + oNode.nodeName + "').OnClick();this.blur();\"";
	l_return += " oncontextmenu=\"javascript:oTree.Find('" + oNode.nodeName + "').OnContextMenu()\"";
	l_return += " class=\"node\"";
	l_return += " value=\"";
	l_return += oNode.array.Find('cate_desc');
	l_return += "\"></input>";
	l_return += "</div>";

	l_return += "</td>";

	l_return += "</tr>";

	//�ӷ����table
	l_return += "<tr>";

	l_return += "<td colspan=3>";
	l_return += "<table border=0 cellspacing=0 cellpadding=0 width=\"100%\"";
	if ( oNode.tree.ShowOnRender == 0 )
		l_return += " style=\"display:none\"";
	l_return += " id='" + oNode.nodeName + "_childrentable'>\n";

	for ( l_name in oNode.children.nodes )
	{
		l_node = oNode.children.nodes[l_name];
		l_return += l_node.RenderTable();
	}
	l_return += "</table>\n";
	l_return += "</td>";

	l_return += "</tr>";
	l_return += "</table>";

	return l_return;
}
//�����ݿ�ɾ�����ݺ���ɾ���ڵ�
function OnDeleteNode(NodeName)
{
	var oNode,sPara;
	var strNodeID="",i,l_s;

	oNode = oTree.Find(NodeName);

	//�ж��Ƿ����ֵܽڵ㣬������򽫽����ƶ����ֵܽڵ㡣
	//���û���ֵܽڵ����ƶ����ýڵ�ĸ��ڵ��ϡ�
	if (oNode.paraNode==null)
		{	strNodeID="";		}
	else
		{
			for (l_s in oNode.paraNode.children.nodes)
			{
				if (l_s!=NodeName){
					strNodeID=l_s;
					break;
					}
			}
			if (strNodeID=="")
				{
					strNodeID=oNode.paraNode.nodeName;
				}
		}
	TrID = NodeName + "_TR";
	document.all.item(TrID).removeNode(true);
	oTree.Remove(NodeName);
	StrLastNode = "";
	oTree.AdjustPic();
	if (strNodeID!=""&&strNodeID!="undefined")
	{	strNodeID=strNodeID+"_Value";}
	SetDBFocus(strNodeID);

}
//ˢ��ҳ��
function RefreshPage()
{
	document.location=document.location;
}
//==������� Ϊ��ʵ��������ʾ������ģ�Ͷ�������ʵ�������Ĵ���