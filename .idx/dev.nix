# To learn more about how to use Nix to configure your environment
# see: https://firebase.google.com/docs/studio/customize-workspace
{ pkgs, ... }: {
  # Which nixpkgs channel to use.
  channel = "stable-23.11"; # or "unstable"

  # Use https://search.nixos.org/packages to find packages
  packages = [
    pkgs.arduino-cli
    pkgs.esptool
    pkgs.python311
    pkgs.python311Packages.pip
    pkgs.cmake
    pkgs.ninja
    pkgs.gnumake
  ];

  # Sets environment variables in the workspace
  env = {};

  idx = {
    # Search for the extensions you want on https://open-vsx.org/ and use "publisher.id"
    extensions = [
      "platformio.platformio-ide"
      "m5stack.m5-unified-ide"
      "espressif.esp-idf-extension"
      "ms-vscode.cpptools"
      "ms-vscode.cpptools-extension-pack"
    ];

    # Enable previews
    previews = {
      enable = false;
      previews = {
      };
    };

    # Workspace lifecycle hooks
    workspace = {
      # Runs when a workspace is first created
      onCreate = {
      };
      # Runs when the workspace is (re)started
      onStart = {
      };
    };
  };
}
