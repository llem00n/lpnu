library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity comparator is
    Port ( good : in  STD_LOGIC_VECTOR (1 downto 0);
           bad : in  STD_LOGIC_VECTOR (1 downto 0);
           mistake : out  STD_LOGIC);
end comparator;
architecture Behavioral of comparator is	
begin
	mistake <= '0' when good = bad else '1';
end Behavioral;

