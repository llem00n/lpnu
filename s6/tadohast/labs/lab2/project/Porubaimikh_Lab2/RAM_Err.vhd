LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.MATH_REAL.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY RAM_Err IS
    PORT (
        A  : IN STD_LOGIC_VECTOR(15 DOWNTO 0);  -- Address input
        DI : IN STD_LOGIC_VECTOR(3 DOWNTO 0);   -- Data input
        OE : IN STD_LOGIC;                      -- Output enable
        WR : IN STD_LOGIC;                      -- Write enable
        CS : IN STD_LOGIC;                      -- Chip select
        DO : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)   -- Data output
    );
END RAM_Err;


ARCHITECTURE Behavioral OF RAM_Err IS
    TYPE RAM_TYPE IS ARRAY (0 TO 65535) OF STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL RAM : RAM_TYPE;

BEGIN    
    PROCESS (A, DI, OE, WR, CS)
        VARIABLE RN : REAL;
		  VARIABLE S1, S2: POSITIVE := 1;
    BEGIN
        IF CS = '0' THEN
            IF WR = '1' THEN
                RAM(TO_INTEGER(unsigned(A))) <= DI;
            END IF;
            IF OE = '1' THEN
                DO <= RAM(TO_INTEGER(unsigned(A)));

                --- Error injection
                UNIFORM(S1, S2, RN);
                IF RN < 0.1 THEN
                    DO(1) <= '1';
                ELSE
                    DO(1) <= '0';
                END IF;
            ELSE
                DO <= (OTHERS => 'Z');
            END IF;
        ELSE
            DO <= (OTHERS => 'Z');
        END IF;
    END PROCESS;
END Behavioral;