module traffic_light_controller(East_road,North_road,West_road,South_road,clk,rst,Emergency,Jam,Empty);
 input clk,rst;
 input [3:0]Emergency,Jam,Empty;//Emergency/Jam/Empty=0000, for east 1000,north 0100,west 0010,south 0001
 output reg[2:0] East_road,North_road,West_road,South_road;//Red=100,Yellow=010,Green=001,Red&Yellow=110,none=000
 
 reg[2:0] state;
 

 parameter [2:0] east_green=3'b000;
 parameter [2:0] east_yellow=3'b001;
 parameter [2:0] north_green=3'b010;
 parameter [2:0] north_yellow=3'b011;
 parameter [2:0] west_green=3'b100;
 parameter [2:0] west_yellow=3'b101;
 parameter [2:0] south_green=3'b110;
 parameter [2:0] south_yellow=3'b111;
 
 reg[4:0] count;
 
 always@(posedge clk, negedge rst)
  begin
   if(!rst)
    begin
    count=5'b00000;
    end
    
   else if(|Emergency)
    begin
    state={Emergency[1]|Emergency[0],Emergency[2]|Emergency[0],1'b0};
    count=5'b00000;
    end
    
   else if(|Jam)
    begin
    state={Jam[1]|Jam[0],Jam[2]|Jam[0],1'b0};
    count=5'b00000;
    end  
    
   else
    begin
     case(state)

      east_green:
         begin
          if(count==5'b10011||Empty==4'b1000)
            begin
             count=5'b00000;
             state=east_yellow;
            end
          else
            begin
            count=count+5'b00001;
            state=east_green;
            end
          end
          
       east_yellow:
         begin
          if(count==5'b00011)
            begin
            count=5'b00000;
            state=north_green;
            end
          else
            begin
            count=count+5'b00001;
            state=east_yellow;
            end
          end
          
      north_green:
         begin
          if(count==5'b10011||Empty==4'b0100)
            begin
            count=5'b00000;
            state=north_yellow;
            end
          else
            begin
            count=count+5'b00001;
            state=north_green;
            end
          end
          
      north_yellow:
         begin
          if(count==5'b00011)
            begin
            count=5'b00000;
            state=west_green;
            end
          else
            begin
            count=count+5'b00001;
            state=north_yellow;
            end
          end
          
      west_green:
         begin
          if(count==5'b10011||Empty==4'b0010)
            begin
            count=5'b00000;
            state=west_yellow;
            end
          else
            begin
            count=count+5'b000001;
            state=west_green;
            end
          end

      west_yellow:
         begin
          if(count==5'b00011)
            begin
            count=5'b00000;
            state=south_green;
            end
          else
            begin
            count=count+5'b00001;
            state=west_yellow;
            end
          end
          
       south_green:
         begin
          if(count==5'b10011||Empty==4'b0001)
            begin
            count=5'b00000;
            state=south_yellow;
            end
          else
            begin
            count=count+5'b00001;
            state=south_green;
            end
          end
          
      south_yellow:
         begin
          if(count==5'b00011)
            begin
            count=5'b00000;
            state=east_green;
            end
          else
            begin
            count=count+5'b00001;
            state=south_yellow;
            end
          end
          
      default:
         begin
          count=5'b00000;
          state=east_green;
          
         end
         
     endcase
    end
   end
   
  //Red=100,Yellow=010,Green=001,Red&Yellow=110,none=000 
  always@(state)
    begin
    if(!rst)
       begin
        East_road=3'b000;
        North_road=3'b000;
        West_road=3'b000;
        South_road=3'b000;       
       end
    else
     begin
     case(state)
    
      east_green:
       begin
        East_road=3'b001;
        North_road=3'b100;
        West_road=3'b100;
        South_road=3'b100;       
       end
        
      east_yellow:
       begin
        East_road=3'b010;
        North_road=3'b110;//
        West_road=3'b100;
        South_road=3'b100;       
       end
       
      north_green:
       begin
        East_road=3'b100;
        North_road=3'b001;
        West_road=3'b100;
        South_road=3'b100;       
       end
         
      north_yellow:
       begin
        East_road=3'b100;
        North_road=3'b010;
        West_road=3'b110;//
        South_road=3'b100;       
       end
       
      west_green:
       begin
        East_road=3'b100;
        North_road=3'b100;
        West_road=3'b001;
        South_road=3'b100;       
       end
        
      west_yellow:
       begin
        East_road=3'b100;
        North_road=3'b100;
        West_road=3'b010;
        South_road=3'b110; //      
       end
       
      south_green:
       begin
        East_road=3'b100;
        North_road=3'b100;
        West_road=3'b100;
        South_road=3'b001;       
       end
         
      south_yellow:
       begin
        East_road=3'b110;//
        North_road=3'b100;
        West_road=3'b100;
        South_road=3'b010;       
       end
                                                       
     endcase
    end
   end
endmodule  