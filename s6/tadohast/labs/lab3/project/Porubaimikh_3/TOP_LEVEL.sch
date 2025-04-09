<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="IN_RST" />
        <signal name="IN_PUSK" />
        <signal name="IN_CLK" />
        <signal name="IN_X(1:0)" />
        <signal name="DD_Y(1:0)" />
        <signal name="DD_Err_STATE(2:0)" />
        <signal name="DD_Err_Y(1:0)" />
        <signal name="DD_STATE(2:0)" />
        <signal name="CMP_Y" />
        <signal name="CMP_STATE" />
        <port polarity="Output" name="IN_RST" />
        <port polarity="Output" name="IN_PUSK" />
        <port polarity="Output" name="IN_CLK" />
        <port polarity="Output" name="IN_X(1:0)" />
        <port polarity="Output" name="DD_Y(1:0)" />
        <port polarity="Output" name="DD_Err_STATE(2:0)" />
        <port polarity="Output" name="DD_Err_Y(1:0)" />
        <port polarity="Output" name="DD_STATE(2:0)" />
        <port polarity="Output" name="CMP_Y" />
        <port polarity="Output" name="CMP_STATE" />
        <blockdef name="DD">
            <timestamp>2024-4-5T7:17:45</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-236" height="24" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="DD_Err">
            <timestamp>2024-4-5T7:17:16</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-236" height="24" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="TSG">
            <timestamp>2024-4-5T7:19:2</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="CMP">
            <timestamp>2024-4-5T7:17:9</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="CMP_S">
            <timestamp>2024-4-5T7:34:51</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <block symbolname="DD" name="XLXI_1">
            <blockpin signalname="IN_RST" name="RST" />
            <blockpin signalname="IN_PUSK" name="PUSK" />
            <blockpin signalname="IN_CLK" name="CLK" />
            <blockpin signalname="IN_X(1:0)" name="X(1:0)" />
            <blockpin signalname="DD_Y(1:0)" name="Y(1:0)" />
            <blockpin signalname="DD_STATE(2:0)" name="STATE(2:0)" />
        </block>
        <block symbolname="DD_Err" name="XLXI_2">
            <blockpin signalname="IN_RST" name="RST" />
            <blockpin signalname="IN_PUSK" name="PUSK" />
            <blockpin signalname="IN_CLK" name="CLK" />
            <blockpin signalname="IN_X(1:0)" name="X(1:0)" />
            <blockpin signalname="DD_Err_Y(1:0)" name="Y(1:0)" />
            <blockpin signalname="DD_Err_STATE(2:0)" name="STATE(2:0)" />
        </block>
        <block symbolname="TSG" name="XLXI_3">
            <blockpin signalname="IN_RST" name="RST" />
            <blockpin signalname="IN_PUSK" name="PUSK" />
            <blockpin signalname="IN_CLK" name="CLK" />
            <blockpin signalname="IN_X(1:0)" name="X(1:0)" />
        </block>
        <block symbolname="CMP" name="XLXI_4">
            <blockpin signalname="DD_Y(1:0)" name="A(1:0)" />
            <blockpin signalname="DD_Err_Y(1:0)" name="B(1:0)" />
            <blockpin signalname="CMP_Y" name="Error" />
        </block>
        <block symbolname="CMP_S" name="XLXI_6">
            <blockpin signalname="DD_STATE(2:0)" name="A(2:0)" />
            <blockpin signalname="DD_Err_STATE(2:0)" name="B(2:0)" />
            <blockpin signalname="CMP_STATE" name="Error" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1136" y="976" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1136" y="1360" name="XLXI_2" orien="R0">
        </instance>
        <branch name="IN_RST">
            <wire x2="832" y1="976" y2="976" x1="784" />
            <wire x2="1008" y1="976" y2="976" x1="832" />
            <wire x2="1008" y1="976" y2="1136" x1="1008" />
            <wire x2="1136" y1="1136" y2="1136" x1="1008" />
            <wire x2="832" y1="528" y2="976" x1="832" />
            <wire x2="960" y1="528" y2="528" x1="832" />
            <wire x2="1008" y1="752" y2="976" x1="1008" />
            <wire x2="1136" y1="752" y2="752" x1="1008" />
        </branch>
        <branch name="IN_PUSK">
            <wire x2="864" y1="1040" y2="1040" x1="784" />
            <wire x2="1024" y1="1040" y2="1040" x1="864" />
            <wire x2="1024" y1="1040" y2="1200" x1="1024" />
            <wire x2="1136" y1="1200" y2="1200" x1="1024" />
            <wire x2="864" y1="576" y2="1040" x1="864" />
            <wire x2="960" y1="576" y2="576" x1="864" />
            <wire x2="1024" y1="816" y2="1040" x1="1024" />
            <wire x2="1136" y1="816" y2="816" x1="1024" />
        </branch>
        <branch name="IN_CLK">
            <wire x2="896" y1="1104" y2="1104" x1="784" />
            <wire x2="1040" y1="1104" y2="1104" x1="896" />
            <wire x2="1040" y1="1104" y2="1264" x1="1040" />
            <wire x2="1136" y1="1264" y2="1264" x1="1040" />
            <wire x2="896" y1="624" y2="1104" x1="896" />
            <wire x2="960" y1="624" y2="624" x1="896" />
            <wire x2="1040" y1="880" y2="1104" x1="1040" />
            <wire x2="1136" y1="880" y2="880" x1="1040" />
        </branch>
        <branch name="IN_X(1:0)">
            <wire x2="928" y1="1168" y2="1168" x1="784" />
            <wire x2="1056" y1="1168" y2="1168" x1="928" />
            <wire x2="1056" y1="1168" y2="1328" x1="1056" />
            <wire x2="1136" y1="1328" y2="1328" x1="1056" />
            <wire x2="928" y1="672" y2="1168" x1="928" />
            <wire x2="960" y1="672" y2="672" x1="928" />
            <wire x2="1056" y1="944" y2="1168" x1="1056" />
            <wire x2="1136" y1="944" y2="944" x1="1056" />
        </branch>
        <branch name="DD_Y(1:0)">
            <wire x2="1536" y1="752" y2="752" x1="1520" />
            <wire x2="1536" y1="752" y2="800" x1="1536" />
            <wire x2="1632" y1="800" y2="800" x1="1536" />
            <wire x2="1744" y1="800" y2="800" x1="1632" />
            <wire x2="1632" y1="528" y2="800" x1="1632" />
            <wire x2="1728" y1="528" y2="528" x1="1632" />
        </branch>
        <branch name="DD_Err_STATE(2:0)">
            <wire x2="1536" y1="1328" y2="1328" x1="1520" />
            <wire x2="1536" y1="1280" y2="1328" x1="1536" />
            <wire x2="1648" y1="1280" y2="1280" x1="1536" />
            <wire x2="1648" y1="1280" y2="1456" x1="1648" />
            <wire x2="1728" y1="1456" y2="1456" x1="1648" />
            <wire x2="1760" y1="1280" y2="1280" x1="1648" />
        </branch>
        <instance x="1744" y="896" name="XLXI_4" orien="R0">
        </instance>
        <instance x="400" y="1200" name="XLXI_3" orien="R0">
        </instance>
        <iomarker fontsize="28" x="960" y="528" name="IN_RST" orien="R0" />
        <iomarker fontsize="28" x="960" y="576" name="IN_PUSK" orien="R0" />
        <iomarker fontsize="28" x="960" y="624" name="IN_CLK" orien="R0" />
        <iomarker fontsize="28" x="960" y="672" name="IN_X(1:0)" orien="R0" />
        <branch name="DD_Err_Y(1:0)">
            <wire x2="1632" y1="1136" y2="1136" x1="1520" />
            <wire x2="1632" y1="864" y2="1136" x1="1632" />
            <wire x2="1680" y1="864" y2="864" x1="1632" />
            <wire x2="1744" y1="864" y2="864" x1="1680" />
            <wire x2="1680" y1="576" y2="864" x1="1680" />
            <wire x2="1728" y1="576" y2="576" x1="1680" />
        </branch>
        <branch name="DD_STATE(2:0)">
            <wire x2="1648" y1="944" y2="944" x1="1520" />
            <wire x2="1648" y1="944" y2="1216" x1="1648" />
            <wire x2="1696" y1="1216" y2="1216" x1="1648" />
            <wire x2="1760" y1="1216" y2="1216" x1="1696" />
            <wire x2="1696" y1="1216" y2="1408" x1="1696" />
            <wire x2="1728" y1="1408" y2="1408" x1="1696" />
        </branch>
        <iomarker fontsize="28" x="1728" y="528" name="DD_Y(1:0)" orien="R0" />
        <iomarker fontsize="28" x="1728" y="576" name="DD_Err_Y(1:0)" orien="R0" />
        <iomarker fontsize="28" x="1728" y="1456" name="DD_Err_STATE(2:0)" orien="R0" />
        <iomarker fontsize="28" x="1728" y="1408" name="DD_STATE(2:0)" orien="R0" />
        <branch name="CMP_Y">
            <wire x2="2160" y1="800" y2="800" x1="2128" />
        </branch>
        <iomarker fontsize="28" x="2160" y="800" name="CMP_Y" orien="R0" />
        <branch name="CMP_STATE">
            <wire x2="2176" y1="1216" y2="1216" x1="2144" />
        </branch>
        <iomarker fontsize="28" x="2176" y="1216" name="CMP_STATE" orien="R0" />
        <instance x="1760" y="1312" name="XLXI_6" orien="R0">
        </instance>
    </sheet>
</drawing>