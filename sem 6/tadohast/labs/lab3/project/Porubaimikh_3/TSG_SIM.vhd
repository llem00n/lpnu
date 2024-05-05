LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ARCHITECTURE Simulation OF TSG IS
  CONSTANT PERIOD : TIME := 10 ns;
  SIGNAL COMPLETE : BOOLEAN := FALSE;
BEGIN
  Clock : PROCESS
  BEGIN
    IF COMPLETE THEN
      WAIT;
    ELSE
      WAIT FOR PERIOD/2;
      CLK <= '0';
      WAIT FOR PERIOD/2;
      CLK <= '1';
    END IF;
  END PROCESS;

  PROCESS
  BEGIN
    -- INITIAL
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- RESET => S0
    WAIT FOR PERIOD;
    RST <= '1';
    PUSK <= '0';
    X <= "00";

    -- S0 => S0
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S0 => S1
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '1';
    X <= "00";

    -- S1 => S5
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S5 => S6
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S6 => S7
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "10";

    -- S7 => S7
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '1';
    X <= "10";

    -- S7 => S0
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "10";

    -- RESET => S0
    WAIT FOR PERIOD;
    RST <= '1';
    PUSK <= '0';
    X <= "00";

    -- S0 => S1
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '1';
    X <= "00";

    -- S1 => S2
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "01";

    -- S2 => S2
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "01";

    -- S2 => S3
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S3 => S7
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "10";

    -- S7 => S0
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- RESET => S0
    WAIT FOR PERIOD;
    RST <= '1';
    PUSK <= '0';
    X <= "00";

    -- S0 => S1
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '1';
    X <= "00";

    -- S1 => S2
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "01";

    -- S2 => S3
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S3 => S4
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S4 => S5
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S5 => S6
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- S6 => S7
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "10";

    -- S7 => S0
    WAIT FOR PERIOD;
    RST <= '0';
    PUSK <= '0';
    X <= "00";

    -- RESET
    WAIT FOR PERIOD;
    RST <= '1';
    PUSK <= '0';
    X <= "00";

    COMPLETE <= TRUE;

    WAIT;
  END PROCESS;
END Simulation;