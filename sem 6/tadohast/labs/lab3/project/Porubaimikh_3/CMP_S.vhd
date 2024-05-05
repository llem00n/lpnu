LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY CMP_S IS
  PORT (
    A, B : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    Error : OUT STD_LOGIC
  );
END CMP_S;

ARCHITECTURE Behavioral OF CMP_S IS
BEGIN
  PROCESS (A, B)
  BEGIN
    IF A = B THEN
      Error <= '0';
    ELSE
      Error <= '1';
    END IF;
  END PROCESS;
END Behavioral;