$n=<STDIN>;   

@arr=split(" ",$n);   

@freq=(0,0,0,0,0,0,0,0,0,0);  

foreach $i (@arr)            
{
    $freq[$i]=$freq[$i]+1; 
}

for( $e = 0; $e < 10; $e = $e + 1 ) 
{  
   if($freq[$e]>0 )           
    {
        print $e," ",$freq[$e];  
        print "\n";
    }
}
