<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Res_G(2:0)" />
        <signal name="XLXN_2(1:0)" />
        <signal name="Res_B(2:0)" />
        <signal name="mistake" />
        <signal name="rst" />
        <signal name="pusk" />
        <signal name="x0" />
        <signal name="x1" />
        <signal name="clk" />
        <signal name="XLXN_17(1:0)" />
        <port polarity="Output" name="Res_G(2:0)" />
        <port polarity="Output" name="Res_B(2:0)" />
        <port polarity="Output" name="mistake" />
        <port polarity="Input" name="rst" />
        <port polarity="Input" name="pusk" />
        <port polarity="Input" name="x0" />
        <port polarity="Input" name="x1" />
        <port polarity="Input" name="clk" />
        <blockdef name="DA_G">
            <timestamp>2023-10-26T12:53:26</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="DA_B">
            <timestamp>2024-3-20T12:13:13</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="comparator">
            <timestamp>2023-10-26T12:53:40</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <block symbolname="DA_G" name="XLXI_1">
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="pusk" name="pusk" />
            <blockpin signalname="x0" name="x0" />
            <blockpin signalname="x1" name="x1" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="XLXN_17(1:0)" name="Y(1:0)" />
            <blockpin signalname="Res_G(2:0)" name="Res(2:0)" />
        </block>
        <block symbolname="DA_B" name="XLXI_2">
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="pusk" name="pusk" />
            <blockpin signalname="x0" name="x0" />
            <blockpin signalname="x1" name="x1" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="XLXN_2(1:0)" name="Y(1:0)" />
            <blockpin signalname="Res_B(2:0)" name="Res(2:0)" />
        </block>
        <block symbolname="comparator" name="XLXI_3">
            <blockpin signalname="XLXN_17(1:0)" name="good(1:0)" />
            <blockpin signalname="XLXN_2(1:0)" name="bad(1:0)" />
            <blockpin signalname="mistake" name="mistake" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="448" y="1472" name="XLXI_2" orien="R0">
        </instance>
        <branch name="XLXN_2(1:0)">
            <wire x2="848" y1="1184" y2="1184" x1="832" />
            <wire x2="896" y1="1184" y2="1184" x1="848" />
        </branch>
        <branch name="Res_G(2:0)">
            <wire x2="864" y1="1008" y2="1008" x1="816" />
        </branch>
        <iomarker fontsize="28" x="864" y="1008" name="Res_G(2:0)" orien="R0" />
        <branch name="Res_B(2:0)">
            <wire x2="864" y1="1440" y2="1440" x1="832" />
        </branch>
        <iomarker fontsize="28" x="864" y="1440" name="Res_B(2:0)" orien="R0" />
        <branch name="mistake">
            <wire x2="1296" y1="1120" y2="1120" x1="1280" />
        </branch>
        <instance x="896" y="1216" name="XLXI_3" orien="R0">
        </instance>
        <iomarker fontsize="28" x="1296" y="1120" name="mistake" orien="R0" />
        <branch name="rst">
            <wire x2="400" y1="752" y2="752" x1="240" />
            <wire x2="400" y1="752" y2="1184" x1="400" />
            <wire x2="448" y1="1184" y2="1184" x1="400" />
            <wire x2="432" y1="752" y2="752" x1="400" />
        </branch>
        <branch name="pusk">
            <wire x2="368" y1="816" y2="816" x1="240" />
            <wire x2="368" y1="816" y2="1248" x1="368" />
            <wire x2="448" y1="1248" y2="1248" x1="368" />
            <wire x2="432" y1="816" y2="816" x1="368" />
        </branch>
        <branch name="x0">
            <wire x2="336" y1="880" y2="880" x1="240" />
            <wire x2="336" y1="880" y2="1312" x1="336" />
            <wire x2="448" y1="1312" y2="1312" x1="336" />
            <wire x2="432" y1="880" y2="880" x1="336" />
        </branch>
        <branch name="x1">
            <wire x2="304" y1="944" y2="944" x1="240" />
            <wire x2="304" y1="944" y2="1376" x1="304" />
            <wire x2="448" y1="1376" y2="1376" x1="304" />
            <wire x2="432" y1="944" y2="944" x1="304" />
        </branch>
        <branch name="clk">
            <wire x2="272" y1="1008" y2="1008" x1="240" />
            <wire x2="272" y1="1008" y2="1440" x1="272" />
            <wire x2="448" y1="1440" y2="1440" x1="272" />
            <wire x2="432" y1="1008" y2="1008" x1="272" />
        </branch>
        <iomarker fontsize="28" x="240" y="1008" name="clk" orien="R180" />
        <iomarker fontsize="28" x="240" y="944" name="x1" orien="R180" />
        <iomarker fontsize="28" x="240" y="880" name="x0" orien="R180" />
        <iomarker fontsize="28" x="240" y="816" name="pusk" orien="R180" />
        <iomarker fontsize="28" x="240" y="752" name="rst" orien="R180" />
        <instance x="432" y="1040" name="XLXI_1" orien="R0">
        </instance>
        <branch name="XLXN_17(1:0)">
            <wire x2="848" y1="752" y2="752" x1="816" />
            <wire x2="848" y1="752" y2="1120" x1="848" />
            <wire x2="896" y1="1120" y2="1120" x1="848" />
        </branch>
    </sheet>
</drawing>