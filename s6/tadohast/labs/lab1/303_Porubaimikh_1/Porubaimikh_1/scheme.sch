<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="Res_G(3:0)" />
        <signal name="Res_B(3:0)" />
        <signal name="B(3:0)" />
        <signal name="mistake" />
        <signal name="XLXN_5(3:0)" />
        <signal name="XLXN_6(3:0)" />
        <signal name="XLXN_7(3:0)" />
        <signal name="XLXN_8(3:0)" />
        <signal name="XLXN_9(3:0)" />
        <port polarity="Output" name="Res_G(3:0)" />
        <port polarity="Output" name="Res_B(3:0)" />
        <port polarity="Input" name="B(3:0)" />
        <port polarity="Output" name="mistake" />
        <blockdef name="ALU_G">
            <timestamp>2024-2-29T18:42:27</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="ALU_B">
            <timestamp>2024-2-29T18:42:8</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="compare">
            <timestamp>2024-2-26T22:34:41</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <block symbolname="ALU_G" name="XLXI_1">
            <blockpin signalname="B(3:0)" name="B(3:0)" />
            <blockpin signalname="Res_G(3:0)" name="S(3:0)" />
        </block>
        <block symbolname="ALU_B" name="XLXI_2">
            <blockpin signalname="B(3:0)" name="B(3:0)" />
            <blockpin signalname="Res_B(3:0)" name="S(3:0)" />
        </block>
        <block symbolname="compare" name="XLXI_3">
            <blockpin signalname="Res_G(3:0)" name="Res_G(3:0)" />
            <blockpin signalname="Res_B(3:0)" name="Res_B(3:0)" />
            <blockpin signalname="mistake" name="mistake" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1488" y="1232" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1936" y="1312" name="XLXI_3" orien="R0">
        </instance>
        <branch name="Res_G(3:0)">
            <wire x2="1904" y1="1200" y2="1200" x1="1872" />
            <wire x2="1904" y1="1200" y2="1216" x1="1904" />
            <wire x2="1936" y1="1216" y2="1216" x1="1904" />
            <wire x2="1904" y1="1088" y2="1200" x1="1904" />
            <wire x2="2000" y1="1088" y2="1088" x1="1904" />
        </branch>
        <branch name="Res_B(3:0)">
            <wire x2="1872" y1="1344" y2="1344" x1="1856" />
            <wire x2="1872" y1="1328" y2="1344" x1="1872" />
            <wire x2="1904" y1="1328" y2="1328" x1="1872" />
            <wire x2="1904" y1="1328" y2="1408" x1="1904" />
            <wire x2="2000" y1="1408" y2="1408" x1="1904" />
            <wire x2="1904" y1="1280" y2="1328" x1="1904" />
            <wire x2="1936" y1="1280" y2="1280" x1="1904" />
        </branch>
        <iomarker fontsize="28" x="2000" y="1088" name="Res_G(3:0)" orien="R0" />
        <iomarker fontsize="28" x="2000" y="1408" name="Res_B(3:0)" orien="R0" />
        <branch name="B(3:0)">
            <wire x2="1408" y1="1200" y2="1200" x1="1360" />
            <wire x2="1488" y1="1200" y2="1200" x1="1408" />
            <wire x2="1408" y1="1200" y2="1344" x1="1408" />
            <wire x2="1472" y1="1344" y2="1344" x1="1408" />
        </branch>
        <iomarker fontsize="28" x="1360" y="1200" name="B(3:0)" orien="R180" />
        <branch name="mistake">
            <wire x2="2352" y1="1216" y2="1216" x1="2320" />
        </branch>
        <iomarker fontsize="28" x="2352" y="1216" name="mistake" orien="R0" />
        <instance x="1472" y="1376" name="XLXI_2" orien="R0">
        </instance>
    </sheet>
</drawing>