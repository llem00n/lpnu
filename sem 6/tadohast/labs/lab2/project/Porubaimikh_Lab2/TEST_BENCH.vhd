LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY TEST_BENCH IS
    PORT (
        A  : OUT STD_LOGIC_VECTOR(15 DOWNTO 0); -- Address
        DI : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);  -- Data input
        OE : OUT STD_LOGIC;                     -- Output enable
        WR : OUT STD_LOGIC;                     -- Write enable
        CS : OUT STD_LOGIC                      -- Chip select
    );
END TEST_BENCH;
