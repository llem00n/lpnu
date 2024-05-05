LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY RAM IS
    PORT (
        A  : IN STD_LOGIC_VECTOR(15 DOWNTO 0);  -- Address input
        DI : IN STD_LOGIC_VECTOR(3 DOWNTO 0);   -- Data input
        OE : IN STD_LOGIC;                      -- Output enable
        WR : IN STD_LOGIC;                      -- Write enable
        CS : IN STD_LOGIC;                      -- Chip select
        DO : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)   -- Data output
    );
END RAM;

ARCHITECTURE Behavioral OF RAM IS
    TYPE ram_type IS ARRAY (0 TO 65535) OF STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL memory : ram_type;

BEGIN
    PROCESS (A, DI, OE, WR, CS)
    BEGIN
        IF CS = '0' THEN
            IF OE = '1' THEN
                DO <= memory(TO_INTEGER(unsigned(A)));
            ELSE
                DO <= (OTHERS => 'Z');
            END IF;
            
            IF WR = '1' THEN
                memory(TO_INTEGER(unsigned(A))) <= DI;
            END IF;
        ELSE
            DO <= (OTHERS => 'Z');
        END IF;
    END PROCESS;
END Behavioral;

