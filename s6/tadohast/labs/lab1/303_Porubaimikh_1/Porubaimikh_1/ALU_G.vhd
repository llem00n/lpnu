
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;


entity ALU_G is
    Port ( B : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (3 downto 0));
end ALU_G;

architecture Behavioral of ALU_G is
signal Y:std_logic_vector(3 downto 0);
begin
process(B,Y)
begin
Y <= std_logic_vector(shift_left(signed(B), 1));
S<=Y;
end process;

end Behavioral;

