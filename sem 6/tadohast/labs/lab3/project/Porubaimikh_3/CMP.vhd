LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY CMP IS
  PORT (
    A, B : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    Error : OUT STD_LOGIC
  );
END CMP;

ARCHITECTURE Behavioral OF CMP IS
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