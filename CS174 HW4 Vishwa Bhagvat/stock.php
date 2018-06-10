<html>
<body>
<div style="border:1px solid black; width:30%; margin-left:37%; margin-right:30%">
  <head>
  <h1 style="text-align:center; border-bottom:inset; margin:0px; font-style:oblique"> Stock Search </h1>

   <style>
table {
    border-collapse: collapse;
}

table, td, th {
    border: 1px solid black;
}
</style>
  </head>
  <form style="margin-top:10px; margin-bottom:0px" name="form" method="get">
  Company Name or Symbol: <input type="text" name="company" id="company" value="<?php if(isset($_GET['company'])){ echo htmlspecialchars($_GET['company']); } else if(isset($_GET['sym'])){ echo htmlspecialchars($_GET['sym']);}    ?>"  oninvalid="alert('Please enter Name or Symbol');"  required > <br/>
  <input style="margin-left:48%; margin-top:10px" type="submit" name="sub" value="Search">
  <input type="button" onclick="window.location.href='stock.php'" value="Clear"> <br/>
  </form>
  <a style="margin-left:32%" href="http://www.markit.com/product/markit-on-demand"> Powered by Markit on Demand </a>
</div>










<?php
 
   
     


  if(isset($_GET['company']))
   {
     
     $a="http://dev.markitondemand.com/MODApis/Api/v2/Lookup/json?input=";
     $b=$_GET['company'];
     $d=str_replace(' ', '.' , $b);
     $c=$a.$d;
     $result=file_get_contents("$c");  
     $data=json_decode($result); 
     echo "<br/>";
     echo "<br/>";
     $countElements=count($data);
     
      
 

     

     if($countElements == 1)
     {
        
      
     $m="http://dev.markitondemand.com/MODApis/Api/v2/Quote/json?symbol=";
       $n=$data[0]->Symbol;
       $p=$m.$n;
       $result5=file_get_contents($p);
       $moredata=json_decode($result5);
        $status=$moredata->Status;
        

           if($status=="SUCCESS")
           {
             $track=1;
         echo "<table class='tab' border='1' align='center'> <tr><td>Name</td><td>";
         echo $moredata->Name;
         echo "</td></tr><tr><td>Symbol</td><td>";
         echo $moredata->Symbol;
         echo "</td></tr><tr><td>Last Price</td><td>";
         echo $moredata->LastPrice;
         echo "</td></tr><tr><td>Change</td><td>";
         $value3=round($moredata->Change, 2);
         echo $value3;
         
         if($value3>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($value3<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><td>Change Percent</td><td>";
         $value4=round($moredata->ChangePercent, 2);
         echo $value4."%";
         if($value4>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($value4<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><td>Timestamp</td><td>";
         echo $moredata->Timestamp;
         echo "</td></tr><tr><td>Market Cap</td><td>";
         $value10=round($moredata->MarketCap/1000000000, 2);
         echo $value10." B";
         echo "</td></tr><tr><td>Volume</td><td>";
         $vol=$moredata->Volume;
         echo number_format($vol);
         echo "</td></tr><tr><td>Change YTD</td><td>";
         $value1=$moredata->ChangeYTD;
         $tt=$moredata->LastPrice;
         $ttdifference=$tt-$value1;
         $ttdifference22=round($ttdifference, 2);
         if($ttdifference22<0)
         {
           echo "(".$ttdifference22.")";
         }
         else
         {
           echo $ttdifference22;
         }
          
         if($ttdifference22>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($ttdifference22<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><td>Change Percent YTD</td><td>";
        
         $r=$moredata->ChangePercentYTD;
         $value2=round($r,2);
         echo $value2."%";
         if($value2>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($value2<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><td>High</td><td>";
         echo $moredata->High;
         echo "</td></tr><tr><td>Low</td><td>";
         echo $moredata->Low;
         echo "</td></tr><tr><td>Open</td><td>";
         echo $moredata->Open;
         echo "</td></tr>";
         echo "</table>";
       }
      else
      {


           echo "<table class='table' border='1' align='center'> <tr> <th width='400px'> There is no stock information available </th> </tr></table>";



      }

}


      





      else if($countElements>0)
      {
      
       
         
         echo "<table class='table' border='1' align='center'> <tr> <th width='400px'> Name </th>  <th width='73px'> Symbol </th> <th width='200px'> Exchange </th>  <th width='78px'> Details </th> </tr>";
         
      
     for($i=0; $i<$countElements; $i++)
     {
     
         
         
         echo "<tr><td>";
         echo $data[$i]->Name;
         echo "</td><td>";
         echo $data[$i]->Symbol;
         echo "</td><td>";
         echo $data[$i]->Exchange;
          echo "</td><td><a href=\"stock.php?sym=".$data[$i] -> Symbol."\">More Info</a>";
         echo "</td></tr>";
    
   
     }
     echo "</table>";
     }

     else 
     {
     
       echo "<table class='table' align='center' border='1'> <tr> <th width='400px'> No Records has been found </th> </tr></table>";
       

       echo "<table class='table' border='1' align='center'> <tr> <th width='400px'> There is no stock information available </th> </tr></table>";
     
   
     }
     
   }







   if(isset($_GET['sym']))
   {
  
     
     $a="http://dev.markitondemand.com/MODApis/Api/v2/Lookup/json?input=";
     $b=$_GET['sym'];
     $d=str_replace(' ', '.' , $b);
     $c=$a.$d;
     $result=file_get_contents("$c");  
     $data=json_decode($result); 
     echo "<br/>";
     echo "<br/>";
     $countElements=count($data);

       $m="http://dev.markitondemand.com/MODApis/Api/v2/Quote/json?symbol=";
       $n=$data[0]->Symbol;
       $p=$m.$n;
       $result5=file_get_contents($p);
       $moredata=json_decode($result5);
        $status=$moredata->Status;



           if($status=="SUCCESS")
           {
             $track=1;
         echo "<table class='tab' border='1px solid black' align='center'> <tr><th>Name</th><td>";
         echo $moredata->Name;
         echo "</td></tr><tr><th>Symbol</th><td>";
         echo $moredata->Symbol;
         echo "</td></tr><tr><th>Last Price</th><td>";
         echo $moredata->LastPrice;
         echo "</td></tr><tr><th>Change</th><td>";
         $value3=round($moredata->Change, 2);
         echo $value3;
         
         if($value3>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($value3<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><th>Change Percent</th><td>";
         $value4=round($moredata->ChangePercent, 2);
         echo $value4."%";
         if($value4>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($value4<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><th>Timestamp</th><td>";
         $time= $moredata->Timestamp;







          echo "".date('Y-m-d'). "  <script type='text/javascript'>


           var currentTime = new Date();
	   var hours = currentTime.getHours();
	   var minutes = currentTime.getMinutes();

           var suffix = 'AM';

	  if (hours >= 12) 
          {
	    suffix = 'PM';
	    hours = hours - 12;
	}

    if (hours == 0) {
    hours = 12;
	}

	if (minutes < 10) 
         {
    	minutes = '0' + minutes;
	}

        if(hours<10)
        {
         hours='0'+hours;
        }

document.write('<b>' + hours + ':' + minutes + ' ' + suffix + '</b>');










         
         </script>";


          



















         
         
         echo "</td></tr><tr><th>Market Cap</th><td>";
         $value10=round($moredata->MarketCap/1000000000, 2);
         echo $value10." B";
         echo "</td></tr><tr><th>Volume</th><td>";
         $vol=$moredata->Volume;
         echo number_format($vol);
         echo "</td></tr><tr><th>Change YTD</th><td>";
         $value1=$moredata->ChangeYTD;
         $tt=$moredata->LastPrice;
         $ttdifference=$tt-$value1;
         $ttdifference22=round($ttdifference, 2);
         if($ttdifference22<0)
         {
           echo "(".$ttdifference22.")";
         }
         else
         {
           echo $ttdifference22;
         }
          
         if($ttdifference22>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($ttdifference22<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><th>Change Percent YTD</th><td>";
        
         $r=$moredata->ChangePercentYTD;
         $value2=round($r,2);
         echo $value2."%";
         if($value2>0)
         {
          echo "<img src='green.png' width='16' height='16'></img>";
         }
         else if ($value2<0)
         {
           echo "<img src='red.png' width='16' height='16'></img>";
         }
         echo "</td></tr><tr><th>High</th><td>";
         echo $moredata->High;
         echo "</td></tr><tr><th>Low</th><td>";
         echo $moredata->Low;
         echo "</td></tr><tr><th>Open</th><td>";
         echo $moredata->Open;
         echo "</td></tr>";
         echo "</table>";
       }
      else
      {


           echo "<table class='table' border='1' align='center'> <tr> <th width='400px'> There is no stock information available </th> </tr></table>";



      }

}



?>









</body>
</html>