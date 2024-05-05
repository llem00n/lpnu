LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ARCHITECTURE sim OF TEST_BENCH IS
    SIGNAL mode: INTEGER := 0; -- 0: Address bus test, 1: Data bus test, 2: Data storing test
BEGIN
    TB_PROCESS: PROCESS
    BEGIN
        -- Initial
        A <= (others => '0');
        DI <= (others => '0');
        OE <= '0';
        WR <= '0';
        CS <= '1';
        WAIT FOR 10 ns;  -- 10 ns

        CS <= '0';

        IF mode = 0 THEN
            OE <= '0';
            WR <= '1';
            WAIT FOR 10 ns; -- 20 ns

            -- Testing address bus
            FOR i IN 0 TO A'length - 1 LOOP
                A <= STD_LOGIC_VECTOR(TO_UNSIGNED(2**i, A'length));
                DI <= (others => '0');
                WAIT FOR 10 ns;
            END LOOP;  -- 180 ns

            WAIT FOR 10 ns; -- 190 ns

            FOR i IN 0 TO A'length - 1 LOOP
                A <= STD_LOGIC_VECTOR(TO_UNSIGNED(2**i, A'length));
                DI <= (others => '1');
                WAIT FOR 10 ns;

                OE <= '1';
                WR <= '0';

                FOR j IN 0 TO A'length - 1 LOOP
                    A <= STD_LOGIC_VECTOR(TO_UNSIGNED(2**j, A'length));
                    WAIT FOR 10 ns;
                END LOOP;

                OE <= '0';
                WR <= '1';
                A <= STD_LOGIC_VECTOR(TO_UNSIGNED(2**i, A'length));
                DI <= (others => '0');
                WAIT FOR 10 ns;
            END LOOP;
        ELSIF mode = 1 THEN
            -- Testing data bus (Address = 0x0000)
            A <= "0000000000000000";
            OE <= '0';
            WR <= '1';
            CS <= '0';
            WAIT FOR 10 ns;

            OE <= '1';
            
            DI <= "0000"; WAIT FOR 10 ns;
            DI <= "0001"; WAIT FOR 10 ns;
            DI <= "0010"; WAIT FOR 10 ns;
            DI <= "0100"; WAIT FOR 10 ns;
            DI <= "1000"; WAIT FOR 10 ns;

            DI <= "1111"; WAIT FOR 10 ns;
            DI <= "1110"; WAIT FOR 10 ns;
            DI <= "1101"; WAIT FOR 10 ns;
            DI <= "1011"; WAIT FOR 10 ns;
            DI <= "0111"; WAIT FOR 10 ns;
        ELSIF mode = 2 THEN
            -- Data storing test

            -- Write zeros
            OE <= '0';
            WR <= '1';

            FOR i IN 0 TO 65535 LOOP
                A <= STD_LOGIC_VECTOR(TO_UNSIGNED(i, A'length));
                DI <= (others => '0');
                WAIT FOR 10 ns;
            END LOOP;

            WR <= '0';
            OE <= '1';

            FOR i IN 0 TO 65535 LOOP
                A <= STD_LOGIC_VECTOR(TO_UNSIGNED(i, A'length));
                WAIT FOR 10 ns;
            END LOOP;

            -- Write ones
            WR <= '1';
            OE <= '0';

            FOR i IN 0 TO 65535 LOOP
                A <= STD_LOGIC_VECTOR(TO_UNSIGNED(i, A'length));
                DI <= (others => '1');
                WAIT FOR 10 ns;
            END LOOP;

            WR <= '0';
            OE <= '1';

            FOR i IN 0 TO 65535 LOOP
                A <= STD_LOGIC_VECTOR(TO_UNSIGNED(i, A'length));
                WAIT FOR 10 ns;
            END LOOP;
        END IF;
		  
		  WAIT;
    END PROCESS TB_PROCESS;
END sim;