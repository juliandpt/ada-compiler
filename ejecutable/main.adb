procedure Main is

   variable_string : String := "Prueba 1";
   variable_int1 : Integer := 2 + 10 ;
   variable_float1 : Float := 1.8;
   variable_bool : Boolean :=  1.8 == variable_float1 ;
   variable_bool2 : Boolean :=  variable_bool ;
   variable_float2: Float := variable_float1 * 2;
   variable_string1: String;


   if variable_float1 < 0.0 then
     variable_int1 := variable_int1 * 2;
    else
      variable_float1 := 2.8;
   end if;
end Main ;