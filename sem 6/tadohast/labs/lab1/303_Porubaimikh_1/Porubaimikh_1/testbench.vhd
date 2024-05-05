
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
LIBRARY UNISIM;
USE UNISIM.Vcomponents.ALL;
ENTITY scheme_scheme_sch_tb IS
END scheme_scheme_sch_tb;
ARCHITECTURE behavioral OF scheme_scheme_sch_tb IS 

   COMPONENT scheme
   PORT( Res_G	:	OUT	STD_LOGIC_VECTOR (3 DOWNTO 0); 
          Res_B	:	OUT	STD_LOGIC_VECTOR (3 DOWNTO 0); 
          B	:	IN	STD_LOGIC_VECTOR (3 DOWNTO 0); 
          mistake	:	OUT	STD_LOGIC);
   END COMPONENT;

   SIGNAL Res_G	:	STD_LOGIC_VECTOR (3 DOWNTO 0);
   SIGNAL Res_B	:	STD_LOGIC_VECTOR (3 DOWNTO 0);
   SIGNAL B	:	STD_LOGIC_VECTOR (3 DOWNTO 0);
   SIGNAL mistake	:	STD_LOGIC;

BEGIN

   UUT: scheme PORT MAP(
		Res_G => Res_G,
		Res_B => Res_B, 
		B => B, 
		mistake => mistake
   );

-- *** Test Bench - User Defined Section ***
   tb : PROCESS
   BEGIN
	B<="0000";
	wait for 15ns;
	B<="0001";
	wait for 15ns;
	B<="0010";
	wait for 15ns;
	B<="0100";
	wait for 15ns;
	B<="1000";
	wait for 15ns;
      WAIT; -- will wait forever
   END PROCESS;
-- *** End Test Bench - User Defined Section ***

END;
