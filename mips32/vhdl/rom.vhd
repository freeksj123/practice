-- Practice to describe rom with VHDL

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity rom is
    generic(
        data_width : integer := 8;
        addr_width : integer := 8
    );
    port(
	read  : in std_logic;
	address : in std_logic_vector(addr_width-1 downto 0);
	data : inout std_logic_vector(data_width-1 downto 0)
    );
end entity rom;

architecture behavior of rom is
    type rom_type is array(0 to 2**address'length-1) of std_logic_vector(data'range);
    
    signal m : rom_type;

begin

    data <= m(to_integer(unsigned(address))) when read = '1' 
            else (others=>'Z');

end architecture behavior;

