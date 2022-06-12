
#pragma once

#include <AzCore/Component/Component.h>

#include <demo-project/demo-projectBus.h>

namespace demo_project
{
    class demo_projectSystemComponent
        : public AZ::Component
        , protected demo_projectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(demo_projectSystemComponent, "{B7A50E0D-99D0-46F7-96E6-0B17E29E3193}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        demo_projectSystemComponent();
        ~demo_projectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // demo_projectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
