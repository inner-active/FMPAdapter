// swift-tools-version:5.3

// Created by Digital Turbine on 03/12/2025.
// Copyright © 2025 Digital Turbine. All rights reserved.
// License: https://www.digitalturbine.com/sdk-license-fyber

import PackageDescription

let package = Package(
    name: "FMPAdapter",
    platforms: [.iOS(.v13)],
    products: [
        .library(
            name: "FMPAdapter",
            targets: ["FMPAdapterTarget"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/inner-active/DTExchangeSDK-iOS-SPM", .exact("8.5.1"))
    ],
    targets: [
        .target(
            name: "FMPAdapterTarget",
            dependencies: [
                .target(name: "FMPAdapter"),
                .product(name: "DTExchangeSDK", package: "DTExchangeSDK-iOS-SPM")
            ],
            path: "Sources/FMPAdapterTarget"
        ),
        .binaryTarget(
            name: "FMPAdapter",
            url: "https://cdn2.inner-active.mobi/fmp-sdk/files/FMPAdapter-iOS-SPM-8.5.1.zip",
            checksum: "cf7862d03eb2e365189e507515b5b0d02d12a4a064788f7784e5e4aec6adb189" 
        ),
    ]
)