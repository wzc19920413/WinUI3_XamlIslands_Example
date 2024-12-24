#pragma once

#include "MyUserControl.g.h"
#include "trace.h"
#include "winrt/microsoft.ui.xaml.media.h"

namespace winrt::SharedComponent::implementation
{
    struct MyUserControl : MyUserControlT<MyUserControl>
    {
        MyUserControl()
        {
            RegisterTraceLogger();
            winrt::Microsoft::UI::Xaml::Media::CompositionTarget::Rendered([](auto sender, auto e) {
                RecordOnRendered();
                });
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void ClickHandler(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&) {
            MyStoreBoard().Completed([](auto&&, auto&&) { RecordAnimationComplete(); });
            MyStoreBoard().Begin();
            this->DispatcherQueue().TryEnqueue(winrt::Microsoft::UI::Dispatching::DispatcherQueuePriority::Low,
                [] { RecordLowPriorityTask(); });
        }
    };
}

namespace winrt::SharedComponent::factory_implementation
{
    struct MyUserControl : MyUserControlT<MyUserControl, implementation::MyUserControl>
    {
    };
}
