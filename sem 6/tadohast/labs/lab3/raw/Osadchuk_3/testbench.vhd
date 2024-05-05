LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
LIBRARY UNISIM;
USE UNISIM.Vcomponents.ALL;
ENTITY scheme_scheme_sch_tb IS
END scheme_scheme_sch_tb;
ARCHITECTURE behavioral OF scheme_scheme_sch_tb IS 

   COMPONENT scheme
   PORT( rst	:	IN	STD_LOGIC; 
          pusk	:	IN	STD_LOGIC; 
          x0	:	IN	STD_LOGIC; 
          x1	:	IN	STD_LOGIC; 
          clk	:	IN	STD_LOGIC; 
          Res_G	:	OUT	STD_LOGIC_VECTOR (2 DOWNTO 0); 
          Res_B	:	OUT	STD_LOGIC_VECTOR (2 DOWNTO 0); 
          mistake	:	OUT	STD_LOGIC);
   END COMPONENT;

   SIGNAL rst	:	STD_LOGIC;
   SIGNAL pusk	:	STD_LOGIC;
   SIGNAL x0	:	STD_LOGIC;
   SIGNAL x1	:	STD_LOGIC;
   SIGNAL clk	:	STD_LOGIC;
   SIGNAL Res_G	:	STD_LOGIC_VECTOR (2 DOWNTO 0);
   SIGNAL Res_B	:	STD_LOGIC_VECTOR (2 DOWNTO 0);
   SIGNAL mistake	:	STD_LOGIC;
	constant Period_clk : time := 5 ns;

BEGIN

   UUT: scheme PORT MAP(
		rst => rst, 
		pusk => pusk, 
		x0 => x0, 
		x1 => x1, 
		clk => clk, 
		Res_G => Res_G, 
		Res_B => Res_B, 
		mistake => mistake
   );
	CLK_Process :process -- read write clock
   begin
           clk <= '0';
       wait for Period_clk/2;
           clk <= '1';
       wait for Period_clk/2;
   end process;

-- *** Test Bench - User Defined Section ***
   tb : PROCESS
   BEGIN
	rst<='0';
   pusk<='0';
   x0<='0';
   x1<='0';
--------------------------------------------------
   wait for Period_clk;
   rst <='1';
   pusk<='0';
   x0  <='0';
   x1  <='0';
--------------------------------------------------
   wait for Period_clk;
   rst<='0';
   pusk<='1';
   x0<='0';
   x1<='0';
--------------------------------------------------
   wait for Period_clk;
   rst<='0';
   pusk<='1';
   x0<='1';
   x1<='0';
--------------------------------------------------
   wait for Period_clk;
   rst<='0';
   pusk<='1';
   x0<='1';
   x1<='0';
--------------------------------------------------
   wait for Period_clk;
   rst<='0';
   pusk<='1';
   x0<='0';
   x1<='0';
--------------------------------------------------
   wait for Period_clk;
   rst<='0';	
   pusk<='1';
   x0<='0';
   x1<='1';
--------------------------------------------------
   wait for Period_clk;
   rst<='0';
   pusk<='0';
   x0<='0';
   x1<='1';
--------------------------------------------------
	wait for Period_clk;
   rst<='1';
   pusk<='0';
   x0<='0';
      WAIT; -- will wait forever
   END PROCESS;
-- *** End Test Bench - User Defined Section ***

END;
