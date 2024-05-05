LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY DA_G IS
	PORT (
		rst : IN STD_LOGIC;
		pusk : IN STD_LOGIC;
		x0 : IN STD_LOGIC;
		x1 : IN STD_LOGIC;
		clk : IN STD_LOGIC;
		Y : OUT STD_LOGIC_VECTOR (1 DOWNTO 0);
		Res : OUT STD_LOGIC_VECTOR (2 DOWNTO 0));
END DA_G;

ARCHITECTURE Behavioral OF DA_G IS
	SIGNAL S : STD_LOGIC_VECTOR(2 DOWNTO 0);
	SIGNAL next_S : STD_LOGIC_VECTOR(2 DOWNTO 0);
BEGIN
	PROCESS (clk, rst)
	BEGIN
		IF rst = '1' THEN
			S <= "000";
			Res <= "000";
		ELSIF rising_edge(clk) THEN
			S <= next_S;
			Res <= next_S;
		END IF;
	END PROCESS;

	PROCESS (S, pusk, x1, x0)
		VARIABLE temp : STD_LOGIC_VECTOR(2 DOWNTO 0);
	BEGIN
		CASE S IS
			WHEN "000" =>

				IF pusk = '0' THEN
					next_S <= "000";
					Y <= "00";
				ELSE
					next_S <= "001";
					Y <= "10";
				END IF;

			WHEN "001" =>

				IF x0 = '0' THEN
					next_S <= "101";
					Y <= "10";
				ELSE
					next_S <= "010";
					Y <= "01";
				END IF;

			WHEN "010" =>
				IF x0 = '0' THEN
					next_S <= "011";
					Y <= "01";
				ELSE
					next_S <= "010";
					Y <= "01";
				END IF;

			WHEN "011" =>
				IF x1 = '0' THEN
					next_S <= "100";
					Y <= "00";
				ELSE
					next_S <= "111";
					Y <= "01";
				END IF;
			WHEN "100" =>
				next_S <= "101";
				Y <= "10";

			WHEN "101" =>
				next_S <= "110";
				Y <= "00";
			WHEN "110" =>
				IF x1 = '0' THEN
					next_S <= "010";
					Y <= "01";
				ELSE
					next_S <= "111";
					Y <= "01";
				END IF;
			WHEN "111" =>
				IF pusk = '0' THEN
					next_S <= "000";
					Y <= "00";
				ELSE
					next_S <= "111";
					Y <= "01";
				END IF;
			WHEN OTHERS =>
				next_S <= "000";
				Y <= "00";
		END CASE;
	END PROCESS;

END Behavioral;