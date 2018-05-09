-- Practice to describe ram with VHDL

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ram is
    generic(
        data_width : integer := 8;
        addr_width : integer := 8
    );
    port(
        clock : in std_logic;
	read  : in std_logic;
	write : in std_logic;
	address : in std_logic_vector(addr_width-1 downto 0);
	data : inout std_logic_vector(data_width-1 downto 0)
    );
end entity ram;

architecture behavior of ram is
    type ram_type is array(0 to 2**address'length-1) of std_logic_vector(data'range);
    
    signal m : ram_type;

begin

    w : process(clock) is

    begin
        if rising_edge(clock) then
	    if write = '1' then
	        m(to_integer(unsigned(address))) <= data;
	    end if;
	end if;
    end process w;


    data <= m(to_integer(unsigned(address))) when read = '1' 
            else (others=>'Z');

end architecture behavior;

