#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "MyUserControl.g.h"
#include "trace.h"
#include "winrt/windows.ui.xaml.media.h"
#include <winrt/Windows.UI.Xaml.Media.Animation.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Core.h>

namespace winrt::SharedComponent::implementation
{
    struct MyUserControl : MyUserControlT<MyUserControl>
    {
        MyUserControl()
        {
            winrt::Windows::UI::Xaml::Media::CompositionTarget::Rendered([](auto sender, auto e) {
                RecordOnRendered();
                });
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const&) {
            MyStoreBoard().Completed([](auto&&, auto&&) { RecordAnimationComplete(); });
            MyStoreBoard().Begin();
            this->Dispatcher().RunAsync(winrt::Windows::UI::Core::CoreDispatcherPriority::Low,
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
