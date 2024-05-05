
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity compare is
    Port ( Res_G : in  STD_LOGIC_VECTOR (3 downto 0);
           Res_B : in  STD_LOGIC_VECTOR (3 downto 0);
           mistake : out  STD_LOGIC);
end compare;

architecture Behavioral of compare is

begin
mistake <= '0' when Res_G=Res_B else '1';

end Behavioral;

