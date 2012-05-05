<!--
 File: control-panel.html 
 Author: Mozhan Soltani
 Date: 05-05-2012
 -->

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<html>
 <head>
  <title>Hovercraft Web Interface</title>
  <script type="text/javascript">
    function displayInc()
   {
    alert("You have clicked on the Increase button!");
   }
   
   function displayDec()
   {
    alert("You have clicked on the Decrease button!");
   }

   function displayQ()
   {
    alert("You have clicked on the Q button!");
   }
   
   function displayW()
   {
    alert("You have clicked on the W button!");
   }
   
   function displayE()
   {
    alert("You have clicked on the E button!");
   }
   
   function displayA()
   {
    alert("You have clicked on the A button!");
   }
   
   function displayS()
   {
    alert("You have clicked on the S button!");
   }
   
   function displayD()
   {
    alert("You have clicked on the D button!");
   }
   
   function displayBreak()
   {
    alert("You have clicked on the Break button!");
   }
  </script>
 </head>
 <body>
  <div id="container" style="width:100%;height:100%;background-color:#FFFFFF;">
   <div id="leftSide" style="width:25%;height:100%;background-color:#FFFFFF;float:left;">
    <div id="leftSide-up1" style="width:30%;height:30%;background-color:#FFFFFF;float:left;">   
    </div> <!--leftSide-up1--> 
	<div id="leftSide-up2" style="width:60%;height:30%;background-color:#FFFFFF;float:left;"> 
     <div id="left_texts">
      <p> 
       <font size="4.5" face="calibri" color="black">
	    <br />
		<br />
		<br />
		<br />
        <b>Battery Level:</b>	
       </font>
      </p> 
	  <p> 
       <font size="4.5" face="calibri" color="black">  
        <b>Pressure Level:</b>	
       </font>
      </p>
     </div>	
    </div> <!--leftSide-up2--> 
	<div id="leftSide-mid1" style="width:30%;height:30%;background-color:#FFFFFF;float:left;">   
    </div> <!--leftSide-mid1-->
	<div id="leftSide-mid2" style="width:60%;height:30%;background-color:#FFFFFF;float:left;">
	<p> 
     <font size="4.5" face="calibri" color="black">  
      <b>GPS Information:</b>	
     </font>
    </p>
    <div id="left_box1" style="width:90%;height:60%;border:2px solid black;" >
    </div> 	
	</div> <!--leftSide-mid2-->
	<div id="leftSide-down1" style="width:30%;height:30%;background-color:#FFFFFF;float:left;">   
    </div> <!--leftSide-down1-->
	<div id="leftSide-down2" style="width:60%;height:35%;background-color:#FFFFFF;float:left;">
	 <p> 
      <font size="4.5" face="calibri" color="black">  
       <b>Hovercarft Speed:</b>	
      </font>
     </p>
     <div id="left_box2" style="width:100%;height:80%;border:2px solid black;text-align:center;" >
	  <br />
	  <font size="4.5" face="calibri" color="black" >
       <b>Current Speed: ...</b> 
      </font>
	  <br />
	  <div id="increase_button" style= "padding:6%;">
       <img border="0" src="increasespeed.png" onclick = "displayInc()"
      	  alt="Increase Button"  width="130" height="35" />
	  </div>
	  <div id="decrease_button">
       <img border="0" src="decreasespeed.png" onclick = "displayDec()"
     	  alt="Increase Button"  width="130" height="35" />
	  </div>
     </div> 	
	</div> <!--leftSide-down2-->
   </div> <!--leftSide--> 
   <div id="center" style="width:57%;height:100%;background-color:#FFFFFF;float:left;">
    <div id="free_space" style="width:100%;height:25%;background-color:#FFFFFF;float:left;">
	</div>
	<div id="logo" style="background-color:#FFFFFF;">
    <img border="0" src="Propeller_3_white.gif" alt="HoverIT logo"
		 width="750" height="250" />
    </div>
   </div> <!--center-->
   <div id="rightSide" style="width:15%;height:100%;background-color:#FFFFFF;float:left;">
    <div id="free_space2" style="width:100%;height:35%;background-color:#FFFFFF;float:left;">
	</div>
    <div id="right_text1">
     <p> 
      <font size="4.5" face="calibri" color="black">
       <b>Current Status:</b> 
      </font>
     </p> 
    </div>
	<div id="rightSide-mid" style="width:100%;height:15%;background-color:#FFFFFF;float:left;">
	<div id="right_box1" style="border:2px solid black; width:90%; height:70%;text-align:center;">
     <font size="4.5" face="calibri" color="black">
	  <br /> 
      <b> Going forward ...</b>
     </font>
    </div>
	</div> <!--rightSide-mid-->
	<div id="rightSide-down" style="width:100%;height:32%;background-color:#FFFFFF;float:left;">
	 <div id="free_space3" style="width:100%;height:25%;background-color:#FFFFFF;float:left;">
	 </div>
	 <div id="Q_button" style="padding:2%;float:left;">
      <img border="0" src="qbutton.png" onclick = "displayQ()" 
	      alt="Q Button"  width="50" height="35" />
     </div>
	 <div id="W_button" style="padding:2%;float:left;">
      <img border="0" src="wbutton.png" onclick = "displayW()" 
	      alt="W Button"  width="50" height="35" />
     </div>
	 <div id="E_button" style="padding:2%;float:left;">
      <img border="0" src="ebutton.png" onclick = "displayE()" 
	      alt="E Button"  width="50" height="35" />
     </div>
	 <div id="A_button" style="padding:2%;float:left;">
      <img border="0" src="abutton.png" onclick = "displayA()" 
	      alt="A Button"  width="50" height="35" />
     </div>
	 <div id="S_button" style="padding:2%;float:left;">
      <img border="0" src="sbutton.png" onclick = "displayS()" 
	      alt="S Button"  width="50" height="35" />
     </div>
	 <div id="D_button" style="padding:2%;float:left;">
      <img border="0" src="dbutton.png" onclick = "displayD()" 
	      alt="D Button"  width="50" height="35" />
     </div>
	 <div id="break_button" style="padding:2%;float:left;">
      <img border="0" src="breakbutton.png" onclick = "displayBreak()"  
	      alt="break Button"  width="168" height ="38" />
     </div>
	</div> <!--right side-down-->
   </div> <!--right side-->
  </div> <!--container--> 
 </body>
</html>   