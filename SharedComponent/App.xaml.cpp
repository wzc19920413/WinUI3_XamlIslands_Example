#include "pch.h"
#include "App.xaml.h"
#include "App.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::SharedComponent::implementation
{
    App::App()
    {
        m_windowsXamlManager = winrt::Windows::UI::Xaml::Hosting::WindowsXamlManager::InitializeForCurrentThread();

        InitializeComponent();
    }

    App::~App()
    {
        Close();
    }

    void App::Close()
    {
        if (m_windowsXamlManager)
        {
            m_windowsXamlManager.Close();
            m_windowsXamlManager = nullptr;
        }
    }

    winrt::Windows::UI::Xaml::Markup::IXamlType App::GetXamlType(winrt::Windows::UI::Xaml::Interop::TypeName const& type)
    {
        return m_xamlMetaDataProvider.GetXamlType(type);
    }

    winrt::Windows::UI::Xaml::Markup::IXamlType App::GetXamlType(winrt::hstring const& fullName)
    {
        return m_xamlMetaDataProvider.GetXamlType(fullName);
    }

    winrt::com_array<winrt::Windows::UI::Xaml::Markup::XmlnsDefinition> App::GetXmlnsDefinitions()
    {
        return m_xamlMetaDataProvider.GetXmlnsDefinitions();
    }
} // namespace winrt::SharedComponent::implementation
