LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY DD_Err IS
  PORT (
    RST : IN STD_LOGIC;
    PUSK : IN STD_LOGIC;
    X : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    CLK : IN STD_LOGIC;
    Y : OUT STD_LOGIC_VECTOR (1 DOWNTO 0);
    STATE : OUT STD_LOGIC_VECTOR (2 DOWNTO 0));
END DD_Err;

ARCHITECTURE Behavioral OF DD_Err IS
  SIGNAL S : STD_LOGIC_VECTOR(2 DOWNTO 0);
  SIGNAL S_NEXT : STD_LOGIC_VECTOR(2 DOWNTO 0);
  SIGNAL X_INT : STD_LOGIC_VECTOR(1 DOWNTO 0);
BEGIN
  PROCESS (CLK, RST)
  BEGIN
    IF RST = '1' THEN
      S <= "000";
      STATE <= "000";
    ELSIF rising_edge(CLK) THEN
      S <= S_NEXT;
      STATE <= S_NEXT;
    END IF;
  END PROCESS;

  PROCESS (S, PUSK, X)
  BEGIN
    X_INT <= X;
    X_INT(0) <= '1';

    CASE S IS
      WHEN "000" =>
        Y <= "00";
        IF PUSK = '0' THEN
          S_NEXT <= "000";
        ELSE
          S_NEXT <= "001";
        END IF;

      WHEN "001" =>
        Y <= "10";
        IF X_INT(0) = '0' THEN
          S_NEXT <= "101";
        ELSE
          S_NEXT <= "010";
        END IF;

      WHEN "010" =>
        Y <= "01";
        IF X_INT(0) = '0' THEN
          S_NEXT <= "011";
        ELSE
          S_NEXT <= "010";
        END IF;

      WHEN "011" =>
        Y <= "01";
        IF X_INT(1) = '0' THEN
          S_NEXT <= "100";
        ELSE
          S_NEXT <= "111";
        END IF;

      WHEN "100" =>
        Y <= "00";
        S_NEXT <= "101";

      WHEN "101" =>
        Y <= "10";
        S_NEXT <= "110";

      WHEN "110" =>
        Y <= "00";
        IF X_INT(1) = '0' THEN
          S_NEXT <= "010";
        ELSE
          S_NEXT <= "111";
        END IF;

      WHEN "111" =>
        Y <= "01";
        IF PUSK = '0' THEN
          S_NEXT <= "000";
        ELSE
          S_NEXT <= "111";
        END IF;
      WHEN OTHERS =>
        S_NEXT <= "000";
    END CASE;
  END PROCESS;
END Behavioral;