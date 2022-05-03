using Microsoft.Win32;
using System.Windows;
using System.Windows.Media;
using UVtools.Core.FileFormats;

namespace Project
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private FileFormat file = null;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void LoadButton_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog dlg = new()
            {
                Filter = "Chitubox format| *.ctb"
            };

            // Show open file dialog box

            // Process open file dialog box results
            if (dlg.ShowDialog() == true)
            {
                // Open document
                file = FileFormat.Open(dlg.FileName);
                LoadLabel.Content = "Loaded!";
                LoadLabel.Foreground = Brushes.LimeGreen;
                LoadLabel.Visibility = Visibility.Visible;
            }
            else
            {
                LoadLabel.Content = "Loading Failed!";
                LoadLabel.Foreground = Brushes.Red;
                LoadLabel.Visibility = Visibility.Visible;
            }
        }

        private void SaveButton_Click(object sender, RoutedEventArgs e)
        {
            if (file == null)
            {
                LoadLabel.Content = "Load File First!";
                LoadLabel.Foreground = Brushes.Red;
                LoadLabel.Visibility = Visibility.Visible;
                return;
            }
            for (int i = 1; i < file.LayerCount; i++)
            {
                if (i % LayerInput.Value == 0)
                {
                    file[i].LiftHeight = (float)LiftHeightInput.Value;
                    file[i].LiftSpeed = (float)LiftSpeedInput.Value;
                    file[i].RetractSpeed = (float)LiftSpeedInput.Value;
                    file[i].WaitTimeAfterLift = (float)WaitTimeInput.Value;
                }
            }

            SaveFileDialog dlg = new()
            {
                FileName = "Output",
                Filter = "Chitubox format| *.ctb"
            };

            if (dlg.ShowDialog() == true)
            {
                // Open document
                file.SaveAs(dlg.FileName);
                LoadLabel.Content = "Saved!";
                LoadLabel.Foreground = Brushes.LimeGreen;
                LoadLabel.Visibility = Visibility.Visible;
            }
        }
    }
}