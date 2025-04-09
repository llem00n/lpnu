<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3a" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="RAM_Err_Output(3:0)" />
        <signal name="RAM_Output(3:0)" />
        <signal name="OE" />
        <signal name="WR" />
        <signal name="CS" />
        <signal name="A(15:0)" />
        <signal name="DI(3:0)" />
        <signal name="CMP_Error" />
        <port polarity="Output" name="RAM_Err_Output(3:0)" />
        <port polarity="Output" name="RAM_Output(3:0)" />
        <port polarity="Output" name="OE" />
        <port polarity="Output" name="WR" />
        <port polarity="Output" name="CS" />
        <port polarity="Output" name="A(15:0)" />
        <port polarity="Output" name="DI(3:0)" />
        <port polarity="Output" name="CMP_Error" />
        <blockdef name="RAM_Err">
            <timestamp>2024-3-27T9:18:16</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="CMP">
            <timestamp>2024-3-28T21:42:41</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="RAM">
            <timestamp>2024-3-28T22:50:27</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="TEST_BENCH">
            <timestamp>2024-3-28T22:50:35</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="RAM_Err" name="XLXI_2">
            <blockpin signalname="OE" name="OE" />
            <blockpin signalname="WR" name="WR" />
            <blockpin signalname="CS" name="CS" />
            <blockpin signalname="A(15:0)" name="A(15:0)" />
            <blockpin signalname="DI(3:0)" name="DI(3:0)" />
            <blockpin signalname="RAM_Err_Output(3:0)" name="DO(3:0)" />
        </block>
        <block symbolname="CMP" name="XLXI_3">
            <blockpin signalname="RAM_Output(3:0)" name="A(3:0)" />
            <blockpin signalname="RAM_Err_Output(3:0)" name="B(3:0)" />
            <blockpin signalname="CMP_Error" name="Error" />
        </block>
        <block symbolname="RAM" name="XLXI_7">
            <blockpin signalname="OE" name="OE" />
            <blockpin signalname="WR" name="WR" />
            <blockpin signalname="CS" name="CS" />
            <blockpin signalname="A(15:0)" name="A(15:0)" />
            <blockpin signalname="DI(3:0)" name="DI(3:0)" />
            <blockpin signalname="RAM_Output(3:0)" name="DO(3:0)" />
        </block>
        <block symbolname="TEST_BENCH" name="XLXI_8">
            <blockpin signalname="OE" name="OE" />
            <blockpin signalname="WR" name="WR" />
            <blockpin signalname="CS" name="CS" />
            <blockpin signalname="A(15:0)" name="A(15:0)" />
            <blockpin signalname="DI(3:0)" name="DI(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1408" y="1328" name="XLXI_2" orien="R0">
        </instance>
        <instance x="1984" y="1008" name="XLXI_3" orien="R0">
        </instance>
        <branch name="RAM_Err_Output(3:0)">
            <wire x2="1888" y1="1040" y2="1040" x1="1792" />
            <wire x2="1888" y1="1040" y2="1088" x1="1888" />
            <wire x2="2000" y1="1088" y2="1088" x1="1888" />
            <wire x2="1888" y1="976" y2="1040" x1="1888" />
            <wire x2="1984" y1="976" y2="976" x1="1888" />
        </branch>
        <branch name="RAM_Output(3:0)">
            <wire x2="1888" y1="608" y2="608" x1="1792" />
            <wire x2="1888" y1="608" y2="912" x1="1888" />
            <wire x2="1984" y1="912" y2="912" x1="1888" />
            <wire x2="2016" y1="608" y2="608" x1="1888" />
        </branch>
        <branch name="OE">
            <wire x2="1152" y1="832" y2="832" x1="896" />
            <wire x2="1152" y1="832" y2="1040" x1="1152" />
            <wire x2="1408" y1="1040" y2="1040" x1="1152" />
            <wire x2="1440" y1="208" y2="208" x1="1152" />
            <wire x2="1152" y1="208" y2="608" x1="1152" />
            <wire x2="1152" y1="608" y2="832" x1="1152" />
            <wire x2="1408" y1="608" y2="608" x1="1152" />
        </branch>
        <branch name="WR">
            <wire x2="1168" y1="896" y2="896" x1="896" />
            <wire x2="1168" y1="896" y2="1104" x1="1168" />
            <wire x2="1408" y1="1104" y2="1104" x1="1168" />
            <wire x2="1440" y1="256" y2="256" x1="1168" />
            <wire x2="1168" y1="256" y2="672" x1="1168" />
            <wire x2="1168" y1="672" y2="896" x1="1168" />
            <wire x2="1408" y1="672" y2="672" x1="1168" />
        </branch>
        <branch name="CS">
            <wire x2="1184" y1="960" y2="960" x1="896" />
            <wire x2="1184" y1="960" y2="1168" x1="1184" />
            <wire x2="1408" y1="1168" y2="1168" x1="1184" />
            <wire x2="1440" y1="304" y2="304" x1="1184" />
            <wire x2="1184" y1="304" y2="736" x1="1184" />
            <wire x2="1184" y1="736" y2="960" x1="1184" />
            <wire x2="1408" y1="736" y2="736" x1="1184" />
        </branch>
        <branch name="A(15:0)">
            <wire x2="1200" y1="1024" y2="1024" x1="896" />
            <wire x2="1200" y1="1024" y2="1232" x1="1200" />
            <wire x2="1408" y1="1232" y2="1232" x1="1200" />
            <wire x2="1440" y1="352" y2="352" x1="1200" />
            <wire x2="1200" y1="352" y2="800" x1="1200" />
            <wire x2="1200" y1="800" y2="1024" x1="1200" />
            <wire x2="1408" y1="800" y2="800" x1="1200" />
        </branch>
        <branch name="DI(3:0)">
            <wire x2="1216" y1="1088" y2="1088" x1="896" />
            <wire x2="1216" y1="1088" y2="1296" x1="1216" />
            <wire x2="1408" y1="1296" y2="1296" x1="1216" />
            <wire x2="1440" y1="400" y2="400" x1="1216" />
            <wire x2="1216" y1="400" y2="864" x1="1216" />
            <wire x2="1408" y1="864" y2="864" x1="1216" />
            <wire x2="1216" y1="864" y2="1088" x1="1216" />
        </branch>
        <branch name="CMP_Error">
            <wire x2="2400" y1="912" y2="912" x1="2368" />
        </branch>
        <iomarker fontsize="28" x="2400" y="912" name="CMP_Error" orien="R0" />
        <iomarker fontsize="28" x="1440" y="208" name="OE" orien="R0" />
        <iomarker fontsize="28" x="1440" y="256" name="WR" orien="R0" />
        <iomarker fontsize="28" x="1440" y="304" name="CS" orien="R0" />
        <iomarker fontsize="28" x="1440" y="352" name="A(15:0)" orien="R0" />
        <iomarker fontsize="28" x="1440" y="400" name="DI(3:0)" orien="R0" />
        <instance x="1408" y="896" name="XLXI_7" orien="R0">
        </instance>
        <instance x="512" y="1120" name="XLXI_8" orien="R0">
        </instance>
        <iomarker fontsize="28" x="2016" y="608" name="RAM_Output(3:0)" orien="R0" />
        <iomarker fontsize="28" x="2000" y="1088" name="RAM_Err_Output(3:0)" orien="R0" />
    </sheet>
</drawing>