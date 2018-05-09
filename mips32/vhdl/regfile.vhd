-- Practice to describe register file with VHDL

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity regfile is
    generic(
        data_width : integer := 32;
        rnum_width : integer := 5
    );
    port(
        clock : in std_logic;
	r1  : in std_logic_vector(rnum_width-1 downto 0);
	r2  : in std_logic_vector(rnum_width-1 downto 0);
	d1 : out std_logic_vector(data_width-1 downto 0)
	d2 : out std_logic_vector(data_width-1 downto 0)
	write : in std_logic;
	rd : in std_logic_vector(rnum_width-1 downto 0);
	data : in std_logic_vector(data_width-1 downto 0)
    );
end entity regfile;

architecture behavior of regfile is
    type regfile_type is array(0 to 2**rnum_width - 1) of std_logic_vector(data'range);
    
    signal r : regfile_type;

begin

    w : process(clock) is

    begin
        if falling_edge(clock) then
	    if write = '1' then
	        r(to_integer(unsigned(rd))) <= data;
	    end if;
	end if;
    end process w;


    d1 <= r(to_integer(unsigned(r1)));
    
    d2 <= r(to_integer(unsigned(r2)));

end architecture behavior;
