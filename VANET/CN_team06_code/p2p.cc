#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"

#include "ns3/netanim-module.h"

// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1
//  |               |
// n2 -------------- n3
//    point-to-point

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("FirstScriptExample");

int main(int argc, char *argv[])
{
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    Time::SetResolution(Time::NS);
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    NodeContainer nodes;
    nodes.Create(4);

    PointToPointHelper pointToPoint;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("50Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("5ms"));

    NetDeviceContainer devices01 = pointToPoint.Install(nodes.Get(0), nodes.Get(1));
    NetDeviceContainer devices23 = pointToPoint.Install(nodes.Get(2), nodes.Get(3));

    InternetStackHelper stack;
    stack.Install(nodes);

    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");

    Ipv4InterfaceContainer interfaces01 = address.Assign(devices01);
    Ipv4InterfaceContainer interfaces23 = address.Assign(devices23);

    UdpEchoServerHelper echoServer(8080);

    ApplicationContainer serverApps01 = echoServer.Install(nodes.Get(0));
    serverApps01.Start(Seconds(1.0));
    serverApps01.Stop(Seconds(20.0));

    UdpEchoClientHelper echoClient01(interfaces01.GetAddress(0), 8080);
    echoClient01.SetAttribute("MaxPackets", UintegerValue(10));
    echoClient01.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient01.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApps01 = echoClient01.Install(nodes.Get(1));
    clientApps01.Start(Seconds(2.0));
    clientApps01.Stop(Seconds(20.0));

    UdpEchoServerHelper echoServer23(8081);

    ApplicationContainer serverApps23 = echoServer23.Install(nodes.Get(2));
    serverApps23.Start(Seconds(1.0));
    serverApps23.Stop(Seconds(20.0));

    UdpEchoClientHelper echoClient23(interfaces23.GetAddress(0), 8081);
    echoClient23.SetAttribute("MaxPackets", UintegerValue(10));
    echoClient23.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient23.SetAttribute("PacketSize", UintegerValue(512));

    ApplicationContainer clientApps23 = echoClient23.Install(nodes.Get(3));
    clientApps23.Start(Seconds(2.0));
    clientApps23.Stop(Seconds(20.0));

    // For ascii trace
    AsciiTraceHelper ascii;
    pointToPoint.EnableAsciiAll(ascii.CreateFileStream("1024.tr"));

    // NetAnim
    AnimationInterface anim("p2p.xml");
    anim.SetConstantPosition(nodes.Get(0), 10.0, 10.0);
    anim.SetConstantPosition(nodes.Get(1), 20.0, 10.0);
    anim.SetConstantPosition(nodes.Get(2), 10.0, 20.0);
    anim.SetConstantPosition(nodes.Get(3), 20.0, 20.0);

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}

