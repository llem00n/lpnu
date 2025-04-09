LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY CMP IS
    PORT (
        A     : IN  STD_LOGIC_VECTOR(3 DOWNTO 0);  -- Input A
        B     : IN  STD_LOGIC_VECTOR(3 DOWNTO 0);  -- Input B
        Error : OUT STD_LOGIC                       -- Error output
    );
END CMP;

ARCHITECTURE Behavioral OF CMP IS
BEGIN
    PROCESS (A, B)
    BEGIN
        IF A = B THEN
            Error <= '0';  -- A and B are equal
        ELSE
            Error <= '1';  -- A and B are not equal
        END IF;
    END PROCESS;
END Behavioral;